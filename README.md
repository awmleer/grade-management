# Grade Management System

### Dependencies

- QT 5.8

### Database Definition

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

### DB Search Functions

```c++
vector<Course> searchCourse();//返回所有的course列表
vector<Course> searchCourseById(int id);//通过id查询
vector<Course> searchCourseByName(QString name);//通过name做模糊查询

vector<Student> searchStudent();//返回所有的student
vector<Student> searchStudentById(int id);//通过id查询
vector<Student> searchStudentByName(QString name);//通过name模糊查询
vector<Student> searchStudentByType(QString type);//通过type查询(精确查询)
```

