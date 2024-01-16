#include <iostream>
#include "time_span.h"
using namespace std;


//creating unit test for checking values
bool CheckValues(TimeSpan time, int hours, int minutes, int seconds)
{
    if ((time.hours() != hours) || (time.minutes() != minutes) || (time.seconds()
!= seconds))
    {
        return false;
    }   
    return true;
}

//This bool checks if the negative seconds are converted to hour, sec, mins
bool NegativeSecond()
{
    TimeSpan ts(-128);
    return CheckValues(ts, 0, -2, -8);
}

//This bool checks if the negative minutes are converted to hour, sec, mins
bool TestNegativeMinute()
{
    TimeSpan ts(8, -23, 0);
    return CheckValues(ts, 7, 37, 0);
}

//This bool checks if the negative hours are converted to hour, sec, mins
bool TestNegativeHour()
{
    TimeSpan ts(-3, 73, 2);
    return CheckValues(ts, -1, -46, -58);
}

//This bool checks if the float seconds are converted to hour, sec, mins
bool TestFloatSeconds()
{
    TimeSpan ts(127.86);
    return CheckValues(ts, 0, 2, 8);
}

//This bool checks if the float minutes are converted to hour, sec, mins
bool TestFloatMinutes()
{
    TimeSpan ts(20.9, 60);
    return CheckValues(ts, 0, 21, 54);
}

//This bool checks if the float hours are converted to hour, sec, mins
bool TestFloatHours()
{
    TimeSpan ts(1.5,30, 127.86);
    return CheckValues(ts, 2, 2, 8);
}

//This bool checks if the minutes of two time span are equal
bool TestEqualMin() 
{
    TimeSpan ts1(5, 6, 7);
    TimeSpan ts2(3, 6, 4);
    if (!CheckValues(ts1, 5, 6, 7) || !CheckValues(ts2, 3, 6, 4)) {
        return false;
    }
    
    if (ts1.minutes() != ts2.minutes()) {
        return false;
    }
    
    return true;
}

//This bool checks if the seconds of two time span are equal
bool TestEqualSeconds() 
{
    TimeSpan ts1(5, 6, 7);
    TimeSpan ts2(3, 4, 7);
    if (!CheckValues(ts1, 5, 6, 7) || !CheckValues(ts2, 3, 4, 7)) {
        return false;
    }
    
    if (ts1.seconds() != ts2.seconds()) {
        return false;
    }
    
    return true;
}

//This bool checks if the hours of two time span are equal
bool TestEqualHours()
 {
    TimeSpan ts1(5, 6, 8);
    TimeSpan ts2(5, 3, 9);
    if (!CheckValues(ts1, 5, 6, 8) || !CheckValues(ts2, 5, 3, 9)) {
        return false;
    }
    
    if (ts1.hours() != ts2.hours()) {
        return false;
    }
    
    return true;
}

//This bool checks if the minutes of two time span are not equal
bool TestNotEqualMin() 
{
    TimeSpan ts1(3, 6, 7);
    TimeSpan ts2(3, 5, 4);
    if (!CheckValues(ts1, 3, 6, 7) || !CheckValues(ts2, 3, 5, 4)) {
        return false;
    }

    if (ts1.minutes() != ts2.minutes()) {
        return true; 
    }

    return false;
}

//This bool checks if the seconds of two time span are not equal
bool TestNotEqualSeconds() 
{
    TimeSpan ts1(7, 3, 4);
    TimeSpan ts2(6, 4, 3);
    if (!CheckValues(ts1, 7, 3, 4) || !CheckValues(ts2, 6, 4, 3)) {
        return false;
    }

    if (ts1.seconds() != ts2.seconds()) {
        return true; 
    }

    return false;
}

//This bool checks if the hours of two time span are not equal
bool TestNotEqualHours() 
{
    TimeSpan ts1(9, 6, 4);
    TimeSpan ts2(8, 5, 1);
    if (!CheckValues(ts1, 9, 6, 4) || !CheckValues(ts2, 8, 5, 1)) {
        return false;
    }

    if (ts1.hours() != ts2.hours()) {
        return true; 
    }

    return false;
}

//This bool checks if minutues of one time span is greater than other
bool TestGreaterMinutes() {
    TimeSpan ts1(5, 7, 7);
    TimeSpan ts2(3, 6, 4);
    if (!CheckValues(ts1, 5, 7, 7) || !CheckValues(ts2, 3, 6, 4)) {
        return false;
    }

    if (ts1.minutes() >= ts2.minutes()) {
        return true;  
    }
    
    return false; 
}

//This bool checks if second of one time span is greater than other
bool TestGreaterSeconds() {
    TimeSpan ts1(6,3,4);
    TimeSpan ts2(1,9,0);
    if (!CheckValues(ts1, 6, 3, 4) || !CheckValues(ts2, 1, 9, 0)) {
        return false;
    }

    if (ts1.seconds() >= ts2.seconds()) {
        return true; 
    }
    
    return false; 
}

//This bool checks if hour of one time span is greater than other
bool TestGreaterHours() {
    TimeSpan ts1(9, 6, 5);
    TimeSpan ts2(8, 1, 5);
    if (!CheckValues(ts1, 9, 6, 5) || !CheckValues(ts2, 8, 1, 5)) {
        return false;
    }

    if (ts1.hours() >= ts2.hours()) {
        return true;  
    }
    
    return false;  
}

//This bool checks if minutues of one time span is equal or greater than other
bool TestGreaterEqualMinutes() {
    TimeSpan ts1(5, 7, 7);
    TimeSpan ts2(3, 6, 4);
    if (!CheckValues(ts1, 5, 7, 7) || !CheckValues(ts2, 3, 6, 4)) {
        return false;
    }

    if (ts1.minutes() >= ts2.minutes()) {
        return true;  
    }
    
    return false; 
}

//This bool checks if seconds of one time span is equal or greater than other
bool TestGreaterEqualSeconds() {
    TimeSpan ts1(6,3,4);
    TimeSpan ts2(1,9,0);
    if (!CheckValues(ts1, 6, 3, 4) || !CheckValues(ts2, 1, 9, 0)) {
        return false;
    }

    if (ts1.seconds() >= ts2.seconds()) {
        return true; 
    }
    
    return false; 
}

//This bool checks if hours of one time span is equal or greater than other
bool TestGreaterEqualHours() {
    TimeSpan ts1(8, 6, 5);
    TimeSpan ts2(8, 1, 5);
    if (!CheckValues(ts1, 8, 6, 5) || !CheckValues(ts2, 8, 1, 5)) {
        return false;
    }

    if (ts1.hours() >= ts2.hours()) {
        return true;  
    }
    
    return false;  
}

//This bool checks if minutues of one time span is less than other
bool TestLessMinutes() {
    TimeSpan ts1(5, 4, 7);
    TimeSpan ts2(3, 5, 4);
    if (!CheckValues(ts1, 5, 4, 7) || !CheckValues(ts2, 3, 5, 4)) {
        return false;
    }

    if (ts1.minutes() < ts2.minutes()) {
        return true;  
    }
    
    return false; 
}

//This bool checks if seconds of one time span is equal or greater than other
bool TestLessSeconds() {
    TimeSpan ts1(6,3,2);
    TimeSpan ts2(1,9,9);
    if (!CheckValues(ts1, 6, 3, 2) || !CheckValues(ts2, 1, 9, 9)) {
        return false;
    }

    if (ts1.seconds() < ts2.seconds()) {
        return true; 
    }
    
    return false; 
}

//This bool checks if hours of one time span is equal or greater than other
bool TestLessHours() {
    TimeSpan ts1(3, 6, 5);
    TimeSpan ts2(8, 1, 5);
    if (!CheckValues(ts1, 3, 6, 5) || !CheckValues(ts2, 8, 1, 5)) {
        return false;
    }

    if (ts1.hours() < ts2.hours()) {
        return true;  
    }
    
    return false;  
}

bool TestLessEqualMinutes() {
    TimeSpan ts1(5, 4, 7);
    TimeSpan ts2(3, 5, 4);
    if (!CheckValues(ts1, 5, 4, 7) || !CheckValues(ts2, 3, 5, 4)) {
        return false;
    }

    if (ts1.minutes() <= ts2.minutes()) {
        return true;  
    }
    
    return false; 
}

//This bool checks if minutues of one time span is equal or less than other
bool TestLessEqualSeconds() {
    TimeSpan ts1(6,3,9);
    TimeSpan ts2(1,9,9);
    if (!CheckValues(ts1, 6, 3, 9) || !CheckValues(ts2, 1, 9, 9)) {
        return false;
    }

    if (ts1.seconds() <= ts2.seconds()) {
        return true; 
    }
    
    return false; 
}

//This bool checks if seconds of one time span is equal or less than other
bool TestLessEqualHours() {
    TimeSpan ts1(8, 6, 5);
    TimeSpan ts2(8, 1, 5);
    if (!CheckValues(ts1, 8, 6, 5) || !CheckValues(ts2, 8, 1, 5)) {
        return false;
    }

    if (ts1.hours() <= ts2.hours()) {
        return true;  
    }
    
    return false;  
}


//This bool checks if the zero values return zeros
bool TestZeros()
{
    TimeSpan ts(0, 0, 0);
    return CheckValues(ts, 0, 0, 0);
}

//This bool checks addition of two time span are equal
bool TestAdd()
{
    TimeSpan ts1, ts2(5), ts3(7, 0), ts4(4, 0, 0);
    TimeSpan add_it_up = ts1 + ts2 + ts3 + ts4;
    return CheckValues(add_it_up, 4, 7, 5);
}

//This bool checks substracton of two time span are equal
bool TestSubstract()
{
    TimeSpan ts1, ts2(5), ts3(7, 0), ts4(4, 0, 0);
    TimeSpan add_it_up = ts1 - ts2 - ts3 - ts4;
    return CheckValues(add_it_up, -4, -7, -5);
}

//This bool checks inplace addition of two time span are equal
bool TestAddInPlace()
{
    TimeSpan ts1(5, 6, 7);
    TimeSpan ts2(1, 1, 1);
    if ((!CheckValues(ts1, 5, 6, 7)) || (!CheckValues(ts2, 1, 1, 1)))
    {
        return false;
    }
    ts1 += ts2;
    if ((!CheckValues(ts1, 6, 7, 8)) || (!CheckValues(ts2, 1, 1, 1)))
    {
        return false;
    }
    return true;
}

//This bool checks inplace substraction of two time span are equal
bool TestMinusInPlace()
{
    TimeSpan ts1(5, 6, 7);
    TimeSpan ts2(1, 1, 1);
    if ((!CheckValues(ts1, 5, 6, 7)) || (!CheckValues(ts2, 1, 1, 1)))
    {
        return false;
    }
    ts1 -= ts2;
    if ((!CheckValues(ts1, 4, 5, 6)) || (!CheckValues(ts2, 1, 1, 1)))
    {
        return false;
    }
    return true;
}


int main()
{
    cout << "Testing TimeSpan Class" << endl;
    if (!NegativeSecond()) cout << "Failed: TestNegativeSecond" << endl;
    if (!TestNegativeMinute()) cout << "Failed: TestNegativeMinute" << endl;
    if (!TestNegativeHour()) cout << "Failed: TestNegativeHour" << endl;
    if (!TestFloatSeconds()) cout << "Failed: TestFloatSeconds" << endl;
    if (!TestFloatMinutes()) cout << "Failed: TestFloatMinutes" << endl;
    if (!TestFloatHours()) cout << "Failed: TestFloatHours" << endl;
    if (!TestZeros()) cout << "Failed: TestZeros" << endl;
    if (!TestNegativeHour()) cout << "Failed: TestNegativeHour" << endl;
    if (!TestAdd()) cout << "Failed: TestAdd" << endl;
    if (!TestSubstract()) cout << "Failed: TestSubstract" << endl;
    if (!TestAddInPlace()) cout << "Failed: TestAddInPlace" << endl;
    if (!TestMinusInPlace()) cout << "Failed: TestMinusInPlace" << endl;
    if (!TestEqualMin()) cout << "Failed: TestEqualMin" << endl;
    if (!TestEqualSeconds()) cout << "Failed: TestEqualSeconds" << endl;
    if (!TestNotEqualMin()) cout << "Failed: TestNotEqualMin" << endl;
    if (!TestNotEqualSeconds()) cout << "Failed: TestNotEqualSeconds" << endl;
    if (!TestNotEqualHours()) cout << "Failed: TestNotEqualHours" << endl;
    if (!TestGreaterEqualMinutes()) cout << "Failed: TestGreaterEqualMinutes" << endl;
    if (!TestGreaterMinutes()) cout << "Failed: TestGreaterMinutes" << endl;
    if (!TestGreaterSeconds()) cout << "Failed: TestGreaterSeconds" << endl;
    if (!TestGreaterHours()) cout << "Failed: TestGreaterHours" << endl;
    if (!TestLessMinutes()) cout << "Failed: TestLessMinutes" << endl;
    if (!TestLessSeconds()) cout << "Failed: TestLessSeconds" << endl;
    if (!TestLessHours()) cout << "Failed: TestLessHours" << endl; 
    if (!TestLessEqualMinutes()) cout << "Failed: TestLessMinutes" << endl;
    if (!TestLessEqualSeconds()) cout << "Failed: TestLessSeconds" << endl;
    if (!TestLessEqualHours()) cout << "Failed: TestLessHours" << endl; 

    cout << "Testing Complete" << endl;


    //input and output operator testing.
    cout << "Now Testing Input and Output Stream" << endl;

    TimeSpan ts1(5, 6, 7);
    std::cout << "TimeSpan ts1: " << ts1 << std::endl; 

    TimeSpan ts2;
    std::cout << "Enter a TimeSpan for ts2:  \n";
    std::cin >> ts2;
    std::cout << "You entered: " << ts2 << std::endl;

} 
