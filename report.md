# 学生成绩管理系统

面向对象程序设计 期末大作业

3150104785 郝广博

3150104804 赵翔宇

3150104802 桂晓琬

3150104957 张正年

GitHub: [awmleer/gradeManagement](https://github.com/awmleer/gradeManagement)

## 总述

本项目用于学生成绩管理，它的主要功能如下：

+ 课程管理
+ 课程查询
+ 学生管理
+ 学生查询
+ 成绩管理
+ 成绩查询

语言：c++

图形框架：QT

## 分工

- GUI：桂晓琬 赵翔宇
- 数据库操作：张正年 郝广博



## SQLite数据库操作

由于成绩管理系统设计较多的数据操作，因此我们采用了本地SQLite数据库。通过QT内置的`QSql`模块，可以非常方便的实现SQL操作。

对于所有数据库的操作，都被放置在了`Db`这个命名空间下面，GUI逻辑层不会直接调用`Db`命名空间的函数，而是通过数据模型的class做间接调用（具体可参加下面对数据模型的介绍）。

### 数据库初始化

数据库初始化主要包括两件事情：

1. 建立和本地数据文件的连接。

   ```c++
   db = QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName("db.sqlite");
   ```

2. 初始化数据库的表定义。

   为了防止重复建立表，我们使用了`CREATE TABLE IF NOT EXISTS`语句。

### 数据库定义（DDL）

一共有三张表，分别为`student`、`course`、`grade`。

```sql
CREATE TABLE IF NOT EXISTS student (
  id INTEGER PRIMARY KEY,
  name VARCHAR(30),
  type VARCHAR(10), -- 'undergraduate' | 'master' | 'doctor'
  enrollmentYear SMALLINT
);

CREATE TABLE IF NOT EXISTS course (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  name VARCHAR(30) UNIQUE,
  description VARCHAR(200)
);

CREATE TABLE IF NOT EXISTS grade (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  studentId INTEGER NOT NULL,
  courseId INTEGER NOT NULL,
  takeTime VARCHAR(20), -- eg. '2016first', '2015second'
  score INTEGER,
  FOREIGN KEY (courseId) REFERENCES course(id),
  FOREIGN KEY (studentId) REFERENCES student(id)
);
```



## 数据模型定义

对于这个项目，一共需要三种数据模型：**学生**、**课程**、**成绩**。

为了逻辑上的清楚，我们把最最底层的数据库操作封装在了这三个类中，从而避免了逻辑层直接调用底层数据库函数。

### 学生

```c++
class Student{
public:
    Student(int id, QString name, QString type, int enrollmentYear);
    int getId();
    QString getName();
    void setName(QString name);
    QString getType();
    void setType(QString type);
    int getEnrollmentYear();
    void setEnrollmentYear(int enrollmentYear);
    bool save();
    bool remove();
    static int create(int id, QString name, QString type, int enrollmentYear);//returns the studentId if success, else returns -1
    static vector<Student> all();
    static vector<Student> searchById(int id);//exact match
    static vector<Student> searchByName(QString name);//fuzzy match
    static vector<Student> searchByType(QString type);//exact match
private:
    int id;
    QString name;
    QString type;
    int enrollmentYear;
};
```

### 课程

```c++
class Course{
public:
    Course(int id, QString name, QString description);
    int getId();
    QString getName();
    void setName(QString name);
    QString getDescription();
    void setDescription(QString description);
    bool save();
    bool remove();
    static int create(QString name, QString description);//returns the courseId if success, else returns -1
    static vector<Course> all();
    static vector<Course> searchById(int id);//exact match
    static vector<Course> searchByName(QString name);//fuzzy match
private:
    int id;
    QString name;
    QString description;
};
```

### 成绩

```c++
class Grade{
public:
    Grade(int id, int studentId, int courseId, QString takeTime, int score);
    int getId();
    int getStudentId();
    int getCourseId();
    QString getTakeTime();
    void setTakeTime(QString takeTime);
    int getScore();
    void setScore(int score);
    Student fetchStudent();
    Course fetchCourse();
    bool save();
    static int create(int studentId, int courseId, QString takeTime, int score);//returns the courseId if success, else returns -1
    bool remove();
    static vector<Grade> all();
    static vector<Grade> searchById(int id);
    static vector<Grade> searchByCourseId(int courseId);
    static vector<Grade> searchByStudentId(int studentId);
    static vector<Grade> searchByTakeTime(QString takeTime);
    static vector<Grade> searchByScore(int min, int max);//score>=min && score<=max
private:
    int id;
    int studentId;
    int courseId;
    QString takeTime;
    int score;
};
```

对于以上三个类，他们的私有属性基本是和数据库的表定义相一致的，通过get和set函数来实现访问和赋值。

每一个类都有`create()`、`save()`、`remove()`函数，其中，`create()`是静态函数，用来在数据库中创建一条相应的记录，如果插入成功返回新增记录对应的id；`save()`是用来把实例修改后的值保存到数据库中（调用`setName()`等函数是不会自动把改动提交到数据库的）；`remove()`是用来把实例对应数据库中的记录删除（并不会删除实例本身）。

对于每一个类，也都有配套的搜索函数，用来做查询，这些搜索函数都是静态函数，返回的类型也都是`vector`。这些搜索函数，本质上并未做特殊的逻辑处理，而是把参数转发给了`Db`模块对应的数据库操作函数。

最后，`grade`类还有`fetchStudent()`和`fetchCourse()`方法，用来获取到某条成绩对应的学生和课程信息，这两个函数本质上也是对`Db`模块下的搜索函数做了封装，但是却对逻辑层的调用来说方便了很多。



## GUI与数据库的交互实现：

### course课程信息的管理

对于课程信息管理的各项内容，我们将其分为增删改查四部分。交互主要通过QT中的 LineEdit与QCombBox类作为接口来实现，以Qstring作为输入并进行相应解析，便于灵活多样的使用输入。其中课程信息的增加通过单独的对话界面来实现，在该界面由用户输入相应的信息进行插入。非数据库层首先会对用户的输入进行简单的检查，并根据出现的问题对用户进行提示。若输入的查询条件通过初步检查，则会对course类中封装好的create函数进行调用，实现相应课程信息的加入。若插入成功，界面会弹出提示说明操作成功，并提示该课程的课程号，否则，则会告知用户出错。

课程信息的查找则是通过对输入的数据进行查找，得到相应的查找结果。该管理系统支持用户自选属性的查找（即输入进行查找的条件不能多于一条，若输入多个条件，则系统会提示只能进行单个条件的查询），以及无条件下所有数据的查找。查找得到的结果会通过 QT中的TableWidget类储存在该界面的表格中。该表格可以作为用户和数据库进行交互的接口。

课程信息的删除和修改都是在查找得到的表格中实现的。用户通过选中表格中记录的相应行，按下该界面上的删除按钮确认即可在数据库中删除当前记录，实现了较为简单方便的交互体验。该过程是通过在删除按钮的槽中调用Course类中的remove函数实现的，其对数据库中的操作进行了较好的封装。课程信息的修改也以类似的方式在选择界面中实现，并通过保存按钮将改变保存到数据库中。由于用户权限的限制，修改的内容只能是课程的名称和描述，课程编号是由系统进行分配的，一般不能修改。

### Student学生信息的管理

学生信息的管理采用了与课程信息相似的管理方式，通过单独的增加页面进行新条目的增加，在查找结果界面利用表格进行查询结果的显示，也可以通过删除和修改按钮进行相应的删和改。

### Grade成绩信息的管理

成绩信息包含了学生，课程，时间和成绩等相关信息，对不同的成绩信息，也以id作为区别的标志。与课程和学生相比，成绩允许的查询条件更为丰富：允许个人成绩的查询，课程成绩的查询，某个时间段的成绩的查询以及某个分数段所有成绩信息的查询。成绩信息的增删改查均通过与上述两种信息相似的方式完成，能够直接体现在数据库中。




## UI界面设计

UI界面一共分为七块：**主界面**、**课程查找**、**课程添加**、**学生查找**、**学生添加**、**成绩查找**、**成绩添加**。

### 主界面MainWindow

主界面是六个主要功能的入口，为了友好，我们插入了一张欢迎的图片。

最上栏我们设置了课程管理、学生管理、成绩管理三大类。

![mainwindow](./pictures/mainwindow.png)

每个大类都可以有两个选项窗。

![00](./pictures/00.png)

第二栏可以直接点击到六项功能的任何一项

### 课程查找CourseSelection

**所有查找功能，在输入两个以上的条件时会有提示，只能输入一个搜索条件，否则会出现错误！**

![hint](./pictures/hint.png)

进入课程查询界面，可以输入课程id或课程名，点击search即可在下方看到结果。

如果是无条件查询，可以直接点击search all。

![courseselection](./pictures/courseselection.png)

### 课程管理CourseManagement

在这里可以进行课程的增删。

添加一门新的课程，需要输入课程名和课程描述，系统会自动分配课程号。

如果需要删除一门课，输入课程的ID，点击remove，即可删除此门课。

![courseinsert](./pictures/courseinsert.png)

### 其他界面OtherWindows

**学生查询、增删和成绩查询、增删大致相同，在此仅给出界面。**

![studentsearch](./pictures/studentsearch.png)

![studentinsert](./pictures/studentinsert.png)

![gradeselect](./pictures/gradeselect.png)

![gradeinsert](./pictures/gradeinsert.png)





















