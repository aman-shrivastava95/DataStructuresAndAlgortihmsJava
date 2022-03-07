#include<bits/stdc++.h>
using namespace std;

bool isLeapYear(int year){
    return (year%400==0) ||(year%4==0 && year%100 !=0) ;
}
int datesBetweenDates(string date1, string date2){
    vector<int> month({0,31,28,31,30,31,30,31,31,30,31,30,31}) ;
    int yy1 = stoi(date1.substr(0,4)) ;
    int yy2 = stoi(date2.substr(0,4)) ;

    int mm1 = stoi(date1.substr(5,2)) ;
    int mm2 = stoi(date2.substr(5,2)) ;

    int dd1 = stoi(date1.substr(8,2)) ;
    int dd2 = stoi(date2.substr(8,2)) ;

    //start from 1971 and see how many days days have passed for date 1
    int n1 = 0 ;
    for(int i=1971;i<yy1;i++){
        if(isLeapYear(i))
        n1+=366 ;
        else
        n1+=365;
    }
    for(int i=1;i<mm1;i++){
        if(i==2 && isLeapYear(yy1))
        n1+=1 ;
        n1+=month[i] ;
    }
    n1+=dd1 ;

     //start from 1971 and see how many days days have passed for date 2
    int n2 = 0 ;
    for(int i=1971;i<yy2;i++){
        if(isLeapYear(i))
        n2+=366 ;
        else
        n2+=365;
    }
    for(int i=1;i<mm2;i++){
        if(i==2 && isLeapYear(yy1))
        n2+=1 ;
        n2+=month[i] ;
    }
    n2+=dd2 ;

    return abs(n2-n1) ;

}