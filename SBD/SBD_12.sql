CREATE TABLE CLASSES(
    CLASS_ID VARCHAR(1),
    CLASS_GRADE INT,
    CLASS_TCH_ID VARCHAR(1),
    CLASS_NUM_OF_STUDENTS INT,
    PRIMARY KEY (CLASS_ID)
);

CREATE TABLE STUDENT(
    ST_ID VARCHAR(1),
    ST_NAME VARCHAR(20),
    ST_CLASS_ID VARCHAR(1),
    ST_GPA FLOAT,
    PRIMARY KEY (ST_ID)
);

CREATE TABLE TEACHERS(
    TCH_ID VARCHAR(1),
    TCH_NAME VARCHAR(20),
    TCH_SUBJECT VARCHAR(10),
    TCH_CLASS_ID VARCHAR(1),
    TCH_MONTHLY_SALARY INT,
    PRIMARY KEY (TCH_ID)
);

INSERT INTO STUDENT VALUE ('1', 'Jack Black', '3', '3.45');
INSERT INTO STUDENT VALUE ('2', 'Daniel White', '1', '3.15');
INSERT INTO STUDENT VALUE ('3', 'Kathrine Star', '1', '3.85');
INSERT INTO STUDENT VALUE ('4', 'Helen Bright', '2', '3.10');
INSERT INTO STUDENT VALUE ('5', 'Steve May', '2', '2.40');

INSERT INTO CLASSES VALUE('1', 10, '3', 21);
INSERT INTO CLASSES VALUE('2', 10, '4', 25);
INSERT INTO CLASSES VALUE('3', 12, '1', 28);

INSERT INTO TEACHERS VALUE('1', 'Elisabeth Grey', 'History', '3', 2500);
INSERT INTO TEACHERS VALUE('2', 'Robert Sun', 'Literature', NULL, 2000);
INSERT INTO TEACHERS VALUE('3', 'John Churchill', 'English', '1', 2350);
INSERT INTO TEACHERS VALUE('4', 'Sara Parker', 'Math', '2', 3000);

ALTER TABLE CLASSES ADD FOREIGN KEY (CLASS_TCH_ID) REFERENCES TEACHERS (TCH_ID);
ALTER TABLE STUDENT ADD FOREIGN KEY (ST_CLASS_ID) REFERENCES CLASSES (CLASS_ID);
ALTER TABLE TEACHERS ADD FOREIGN KEY (TCH_CLASS_ID) REFERENCES CLASSES (CLASS_ID);
