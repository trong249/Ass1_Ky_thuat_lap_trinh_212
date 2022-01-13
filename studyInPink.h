/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2022
    * Author: Tran Huy
    * Date: 06.01.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

int firstMeet(int& EXP1, int& EXP2, const int& E1){
    //Complete this function to gain point on task 1

    // Case 1:
    if( EXP1>=0 && EXP1<=399 ){
        int case1=25;
        int case2=50;
        int case3=85;

        if ( E1>=0 && E1<=49 ){
            EXP2+=case1;
        }

        if ( E1>=50 && E1<=99 ){
            EXP2+=case2;
        }

        if ( E1>=100 && E1<=149 ){
            EXP2+=case3;
        }

        if ( E1>=150 && E1<=199 ){
            EXP2+=case1+case2;
        }

        if ( E1>=200 && E1<=249 ){
            EXP2+=case1+case3;
        }

        if ( E1>=250 && E1<=299 ){
            EXP2+=case2+case3;
        }

        if ( E1>=50 && E1<=99 ){
            EXP2+=case1+case2+case3;
        }   

        if ( E1%2!=0 ){
            EXP1=ceil((float)EXP1+(float)E1/10);
        }
        else {
            EXP1=ceil((float)EXP1-(float)E1/5);
        }
    }
    
    // Case 2:
    if( E1>=400 && E1<=999 ){
        // information 1
        if ( E1>=400 && E1<=499 ){
            EXP2=ceil( (float)EXP2+(float)E1/7+9);
        }
        // information 2
        if ( E1>=500 && E1<=599 ){
            EXP2=ceil( (float)EXP2+(float)E1/9+11);
        }
        // information 3
        if ( E1>=600 && E1<=699 ){
            EXP2=ceil( (float)EXP2+(float)E1/5+6);
        }
        // information 4
        if ( E1>=700 && E1<=799 ){
            EXP2=ceil( (float)EXP2+(float)E1/7+9);
            if(EXP2>200){
                EXP2=ceil( (float)EXP2+(float)E1/9+11);
            }
        }
        // information 5
        if ( E1>=800 && E1<=999 ){
            EXP2=ceil( (float)EXP2+(float)E1/7+9);
            EXP2=ceil( (float)EXP2+(float)E1/9+11);
            if(EXP2>600){
                EXP2=ceil( (float)EXP2+(float)E1/5+6);
                EXP2=ceil( (float)EXP2*0.15 + (float)EXP2 );
            }
        }

        EXP1=ceil( (float)EXP1-(float)EXP1*0.1 );
    }

    if(EXP1>900) EXP1=900;
    if(EXP1<0) EXP1=0;

    if(EXP2>900) EXP2=900;
    if(EXP2<0) EXP2=0;

    return EXP1+EXP2;
}

int investigateScene(int& EXP1, int& EXP2, int& HP2, int& M2, const int& E2){
    //Complete this function to gain point on task 2
    // Phase 1
    if ( E2>=0 && E2<=299){
        // ring
        EXP2=ceil( (float)EXP2+ (float)E2/9+10 );
        EXP1=ceil( (float)EXP1+ ((float)E2/9+10)/3 );
    }
    if ( E2>=300 && E2<=499){
        // ring
        EXP2=ceil( (float)EXP2+ (float)E2/9+10 );
        EXP1=ceil( (float)EXP1+ ((float)E2/9+10)/3 );
        // jacket
        EXP2=ceil( (float)EXP2+ (float)E2*0.35 );
        EXP1=ceil( (float)EXP1+ (float)E2*0.35/3 );
    }
    if ( E2>=500 && E2<=999){
        // ring
        EXP2=ceil( (float)EXP2+ (float)E2/9+10 );
        EXP1=ceil( (float)EXP1+ ((float)E2/9+10)/3 );
        // jacket
        EXP2=ceil( (float)EXP2+ (float)E2*0.35 );
        EXP1=ceil( (float)EXP1+ (float)E2*0.35/3 );
        // baggage
        EXP2=ceil( (float)EXP2+ ( (float)E2/9+10+(float)E2*0.35 )*0.17 );
        EXP1=ceil( (float)EXP1+ ( (float)E2/9+10+(float)E2*0.35 )*0.17/3 );
    }


    // Phase 2
    HP2=ceil( (float)HP2 - (pow((float)E2,3) / pow(2,23)) );
    if(E2%2==0){
        M2 = ceil( (float)M2 + (pow((float)E2,2)/50) );
    }

    if(HP2<0) HP2=0;
    if(EXP1>900) EXP1=900;
    if(EXP2>900) EXP2=900;
    if(M2>2000) M2=2000;

    return EXP2+HP2+M2+EXP1;
}

int traceLuggage(int& HP1, int& EXP1, int& M1, const int& E3){
    //Complete this function to gain point on task 3
    // Road 1

    int P1[9]={1, 3, 5, 7, 9, 11, 13, 15, 17};
    bool checkRoad1 = false;
    for(int i = 0; i < 9; i++){
        P1[i] = ( P1[i] + E3 ) % 26 + 65;
        if( P1[i] == 80 ){
            checkRoad1 = true;
            HP1 -= P1[i]*(i+1)*2;
            EXP1 += (1000-P1[i]*(i+1))%101;
            M1 = ceil( (float)M1-(float)E3*(i+1)/9);
            break;
        }
    }
    if( checkRoad1==false ){
        M1=ceil( (float)M1-(float)E3*9);
    }
        


    // Road 2
    int P2[7]={2,3,5,7,11,13,17};
    int s=0,m=0;
    bool checkRoad2=false;
    for(int i=0;i<7;i++){
        s+=P2[i];
        P2[i]=(P2[i]+E3)%26;
    }
    m=ceil(s/7);
    for (int i = 0; i < 7; i++)
    {
        P2[i] = (P2[i] + s + m)%26 + 65;
        if( P2[i] == 80 ){
            checkRoad2 = true;
            HP1 -= P2[i]*(i+1)*2;
            EXP1 += (1000-P2[i]*(i+1))%101;
            M1 = ceil( (float)M1-(float)E3*(i+1)/9);
            break;
        }
    }
    if( checkRoad2==false ){
        M1=ceil( (float)M1-(float)E3*7*7/9);
    }
    
    // Road 3
    int P3[20]={4,16,36,64,100,144,196,256,324,400,484,576,676,784,900,1024,1156,1296,1444,1600};
    bool checkRoad3=false;
    int max=0;
    for(int i = 0; i<20; i++){
        P3[i]=(P3[i] + E3*E3)%113;
        if(P3[i]>max){
            max=P3[i];
        }
    }
    for(int i = 19; i>=0; i--){
        P3[i]= ceil( (P3[i]+E3)/max);
        P3[i]=P3[i]%26 + 65;

        if( P3[i] == 80 ){
            checkRoad3 = true;
            HP1 -= P3[i]*(20-i)*3;
            EXP1 += (3500-P3[i]*(20-i))%300;
            M1 = ceil( (float)M1-(float)E3*(20-i)/9);
            break;
        }
    }
    if( checkRoad3==false ){
        M1=ceil( (float)M1-(float)E3*20*20/9);
    }

    // Road 4
    int P4[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    bool checkRoad4=false;
    int min=999,min_idx=0;
    for(int i=0; i<12;i++){
        int a=ceil( pow( (float)E3/29,3 ) );
        P4[i] = ( P4[i] +  a) % 9;
        if(P4[i]<min){
            min=P4[i];
            min_idx=i;
        }
    }
    for(int i=11; i>=0; i--){
        int a=ceil( (float)(P4[i]+E3)*(min/min_idx) );
        P4[i]= a%26+65;
        if( P4[i] == 80 ){
            checkRoad4 = true;
            HP1 -= P4[i]*(12-i)*4;
            EXP1 += (4500-P4[i]*(12-i))%400;
            M1 = ceil( (float)M1-(float)E3*(12-i)/9);
            break;
        }
    }
    if( checkRoad4==false ){
        M1=ceil( (float)M1-(float)E3*12*12/9);
    }

    if(M1<0) M1=0;

    if( !(checkRoad1||checkRoad2||checkRoad3||checkRoad4) ){
        HP1-=(59*E3)%900;
        EXP1-=(79*E3)%300;
        if(EXP1<0) EXP1=0;
        if(HP1<0) HP1=0;
        return -1;
    }
    else{
        if(HP1<0) HP1=0;
        if(EXP1>900) EXP1=900;
        return HP1+EXP1+M1;
    }
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
