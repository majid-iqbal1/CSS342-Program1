#ifndef TIME_SPAN_H_
#define TIME_SPAN_H_
#include <iostream>

class TimeSpan
{
   
public:
    //Constructors
    TimeSpan();
    TimeSpan(double hours, double minutes, double seconds);
    TimeSpan(double minutes, double seconds);
    TimeSpan(double seconds);

    //getters 
    int hours() const;
    int minutes() const;
    int seconds() const;

    //setter
    bool set_time(int hours, int minutes, int seconds);

    //Arithemtic, unary, and augmented operators
    TimeSpan& operator+=(const TimeSpan& rhs);
    TimeSpan operator+(const TimeSpan& rhs) const;
    TimeSpan& operator-=(const TimeSpan& rhs);
    TimeSpan operator-(const TimeSpan& rhs) const;
    TimeSpan operator-() const;

    //boolean comparsion operators
    bool operator==(const TimeSpan& rhs) const;
    bool operator!=(const TimeSpan& rhs) const;
    bool operator>=(const TimeSpan& rhs) const;
    bool operator>(const TimeSpan& rhs) const;
    bool operator<=(const TimeSpan& rhs) const;
    bool operator<(const TimeSpan& rhs) const;    

    //input output stream operators
    friend std::ostream& operator<<(std::ostream& stream, const TimeSpan& rhs);
    friend std::istream& operator>>(std::istream& stream, TimeSpan& rhs);

private:
    //Data members and convert function
    double hours_;
    double minutes_;
    double seconds_;
    void convert(double hours, double minutes, double seconds);
};

#endif