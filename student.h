//
//  student.h
//  studentSystem
//
//  Created by ChanJose on 2019/1/2.
//  Copyright © 2019年 ChanJose. All rights reserved.
//

#ifndef student_h
#define student_h
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node {
    string id; // 学生的学号
    string name; // 姓名
    string birthday; // 出生日期：如1995-01-01
    int sex; // 1:表示是男生，0:表示是女生
    string phone; // 电话
    string address; // 地址
    Node *next;
};

Node *Create(); // 新建同学录
bool InsertStudent(Node *head); // 向学生通讯录插入学生信息
bool DeleteStudent(Node *head, string id); // 在通讯录中删除学生信息
Node *ReadFromFile(); // 从文件中读取通讯录信息
bool WriteToFile(Node *head); // 向文件写入学生通讯录信息
bool FindStudent(Node *head, string id); // 在通讯录中查询学生信息（按学号查询）
void PrintStudent(Node *head); // 在屏幕中输出全部学生信息

#endif /* student_h */

