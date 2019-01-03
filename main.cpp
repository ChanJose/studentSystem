//
//  main.cpp
//  studentSystem：学生通讯录管理系统
//
//  Created by ChanJose on 2019/1/2.
//  Copyright © 2019年 ChanJose. All rights reserved.
//  测试数据： 20192101011 ChanJose 2000-01-01 1 15626453333 广东广州
//           20192101012 juan 2000-01-02 0 15626453334 广东广州
//           20192101013 feng 2000-01-03 0 15626453335 广东广州
#include <iostream>
#include "student.h"
using namespace std;

int main(int argc, const char * argv[]) {
    int choice;
    string id;
    bool finished = false;
    
    Node *head = NULL;
    while(!finished) {
        cout << "\n*********菜单*********\n";
        cout << "1:新建学生通讯录\n";
        cout << "2:向学生通讯录插入学生信息\n";
        cout << "3:在通讯录删除学生信息\n";
        cout << "4:从文件中读取通讯录信息\n";
        cout << "5:向文件写入通讯录信息\n";
        cout << "6:在通讯录中查询学生信息（按学号查询）\n";
        cout << "7:在屏幕中输出全部学生信息\n";
        cout << "8:退出\n";
        cout << "请输入选择（1-8）：\n";
        cin >> choice;
        switch(choice) {
            case 1:
                head = Create(); // 新建学生通讯录
                break;
            case 2:
                if(InsertStudent(head)) // 向学生通讯录插入学生信息
                    cout << "插入学生信息成功!" << endl;
                else
                    cout << "插入学生信息失败!" << endl;
                break;
            case 3: // 在通讯录删除学生信息
                cout << "请输入要删除的学生通讯录信息的学号:";
                cin >> id;
                if(DeleteStudent(head, id))
                    cout << "删除成功！" << endl;
                else
                    cout << "删除失败!" << endl;
                break;
            case 4: // 从文件中读取通讯录信息
                head = ReadFromFile(); 
                break;
            case 5: // 向文件写入通讯录信息
                WriteToFile(head); 
                break;
            case 6: // 在通讯录中查询学生信息（按学号查询）
                cout << "请输入要查找的学生信息的学号：";
                cin >> id;
                if(FindStudent(head, id))
                    cout << "查找成功!" << endl;
                else
                    cout << "查找失败！" << endl;
                break;
            case 7: // 在屏幕中输出全部学生信息
                PrintStudent(head);
                break;
            case 8:
                finished = true;
                break;
            default:
                cout << "输入选择错误，请重新输入!" << endl;
        }
    }
    return 0;
}
