/**
 * @file 3-3-04模拟实现渡口管理.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-11-03
 * 渡口管理方案：
 * 某汽车轮渡口，过江渡船每次能载10辆车过江。
 * 过江车辆分为客车类和货车类，上渡船有如下规定:
 * 1. 同类车先到先上船（队列管理）
 * 2. 客车先于货车上船，且每上4辆客车，才允许放上1辆货车;若等待客车不足4辆，则以货车代替
 * 3. 若无货车等待，允许客车都上船。
 * 试设计一个算法模拟渡口管理。
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <string>
#include <queue>
#include <vector>

#define MAXSIZE 10

using namespace std;

/**
 * @brief 函数打印计算管理结果,就按照要求依次输出即可
 *
 * @param carStr 汽车到达的先后顺序
 * @param truckStr 货车到达的先后顺序
 */
void Manage(const string &carStr, const string &truckStr)
{
    queue<char> car;
    queue<char> truck;
    //按照字符串，入对
    for (int i = 0; i < carStr.length(); i++)
    {
        car.push(carStr[i]);
    }
    for (int i = 0; i < truckStr.length(); i++)
    {
        truck.push(truckStr[i]);
    }
    while (!car.empty() && !truck.empty())
    {
        //每一次的渡船,最大大小为10
        vector<char> ship;
        while (ship.size() != MAXSIZE)
        {
            if (car.size() >= 4)
            {
                for (int times = 0; times < 4; times++)
                {
                    ship.push_back(car.front());
                    car.pop();
                }
                ship.push_back(truck.front());
                truck.pop();
            }
            else
            {
                //客车不足4个，客车全部上船，剩下的用货车补
                while (!car.empty())
                {
                    ship.push_back(car.front());
                    car.pop();
                }
                //如果要装满一船还需要的货车数
                int remain = MAXSIZE - ship.size();
                for (int i = 0; i < remain; i++)
                {
                    if (truck.empty())
                    {
                        //没有车辆了，这艘船没装满也要走
                        break;
                    }
                    ship.push_back(truck.front());
                    truck.pop();
                }
            }
        }
        //打印这次结果
        for (int i = 0; i < ship.size(); i++)
        {
            cout << ship[i] << " ";
        }
        cout << endl;
    }
    //可能没有客车，可能没有货车
    while (!car.empty())
    {
        //客车依次上船
        for (int i = 0; i < MAXSIZE && !car.empty(); i++)
        {
            cout << car.front() << " ";
            car.pop();
        }
        cout << endl;
    }
    //剩下的货车,题目没给,这里让货车和客车处理相同
    while (!truck.empty())
    {
        //客车依次上船
        for (int i = 0; i < MAXSIZE && !truck.empty(); i++)
        {
            cout << truck.front() << " ";
            truck.pop();
        }
        cout << endl;
    }
}

int main()
{
    // Manage("abcdef", "ABCD");
    // Manage("abcdefgh", "ABCDEF");
    Manage("abcdefghigk", "");
    return 0;
}