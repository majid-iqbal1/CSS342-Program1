#include "time_span.h"
#include <cmath>

// The default constructor- it initialize the value to zero.
TimeSpan::TimeSpan() : hours_(0), minutes_(0), seconds_(0) 
{

}

//These three constructors below are parameterized constructors that receives double it uses convert function to covert them to seonds than separate them into hours, minutes and seconds.
TimeSpan::TimeSpan(double hours, double minutes, double seconds)
{
    convert(hours, minutes, seconds);

}

TimeSpan::TimeSpan(double minutes, double seconds)
{
    convert(0, minutes, seconds);
}

TimeSpan::TimeSpan(double seconds)
{
    convert(0, 0, seconds);
}

//These get methods return the hours, minutes and seconds as integers
int TimeSpan::hours() const
{
    return hours_;
}

int TimeSpan::minutes() const
{
    return minutes_;
}

int TimeSpan::seconds() const
{
    return seconds_;
}

// This method rounds & converts everything into seconds and then separate them into hours, mins, and seconds.
void TimeSpan::convert(double hours, double minutes, double seconds) 
{
    int totalSeconds = (round((hours * 3600) + (minutes * 60) + seconds));

    this->hours_ = totalSeconds / 3600;
    totalSeconds %= 3600;
    this->minutes_ = totalSeconds / 60;
    this->seconds_ = totalSeconds % 60;
}

//The set method sets hours, mins and secs and if it's true it returns.
bool TimeSpan::set_time(int hours, int minutes, int seconds){
    this-> hours_ = hours;
    this-> minutes_ = minutes;
    this-> seconds_ = seconds;
    return true;

}

//This operator does in-place addition of rhs to current hours, mins and secs.
TimeSpan& TimeSpan::operator+=(const TimeSpan& rhs )
{
    this->hours_ += rhs.hours_;
    this->minutes_ += rhs.minutes_;
    this->seconds_ += rhs.seconds_;
    return *this;

}

// This operator adds two timespan and returns the final values
TimeSpan TimeSpan::operator+(const TimeSpan& rhs) const
{
    return TimeSpan(hours_ + rhs.hours_, minutes_ + rhs.minutes_, seconds_ + rhs.seconds_);
}

//The operator substract in-place of rhs to current object hours, mins and secs.
TimeSpan& TimeSpan::operator-=(const TimeSpan& rhs)
{
    this->hours_ -= rhs.hours_;
    this->minutes_ -= rhs.minutes_;
    this->seconds_ -= rhs.seconds_;
    return *this;
}

//This operator substracts two timespan and returns the final values
TimeSpan TimeSpan::operator-(const TimeSpan& rhs ) const
{
    return TimeSpan(hours_ - rhs.hours_, minutes_ - rhs.minutes_, seconds_ - rhs.seconds_);
}

//this is urinay operator. It negates the timespan
TimeSpan TimeSpan::operator-() const
{
    return TimeSpan(-(this->hours_), -(this->minutes_), -(this->seconds_));
}

//This operator check if current and new object hours, mins and secs are equal
bool TimeSpan::operator==(const TimeSpan& rhs) const
{
    return !(this->hours_ != rhs.hours_ || this->minutes_ != rhs.minutes_ || this->seconds_ != rhs.seconds_);   
}

//This operator check if current and new object hours, mins and secs are not equal
bool  TimeSpan::operator!=(const TimeSpan& rhs) const
{
    return (this->hours_ != rhs.hours_ || this->minutes_ != rhs.minutes_ || this->seconds_ != rhs.seconds_);
}

//This operator check if current and new object seconds are equal or geater than each other
bool  TimeSpan::operator>=(const TimeSpan& rhs) const
{
    int secondsLHS = (hours_ * 3600) + (minutes_ * 60) + seconds_;
    int secondsRHS = (rhs.hours_ * 3600) + (rhs.minutes_ * 60) + rhs.seconds_;
    return secondsLHS >= secondsRHS;
    
}

//This operator check if current and new object seconds are geater than other
bool  TimeSpan::operator>(const TimeSpan& rhs) const
{
    int secondsLHS = (hours_ * 3600) + (minutes_ * 60) + seconds_;
    int secondsRHS = (rhs.hours_ * 3600) + (rhs.minutes_ * 60) + rhs.seconds_;
    return secondsLHS > secondsRHS;
}

//This operator check if current and new object seconds are equal or less than each other
bool  TimeSpan::operator<=(const TimeSpan& rhs) const
{
    int secondsLHS = (hours_ * 3600) + (minutes_ * 60) + seconds_;
    int secondsRHS = (rhs.hours_ * 3600) + (rhs.minutes_ * 60) + rhs.seconds_;
    return secondsLHS <= secondsRHS;
}

//This operator check if current and new object seconds are less than other
bool  TimeSpan::operator<(const TimeSpan& rhs) const
{
    int secondsLHS = (hours_ * 3600) + (minutes_ * 60) + seconds_;
    int secondsRHS = (rhs.hours_ * 3600) + (rhs.minutes_ * 60) + rhs.seconds_;
    return secondsLHS < secondsRHS;
}

//This is the out stream operator that prints hours, mins and secs.
std::ostream& operator<<(std::ostream& ostream, const TimeSpan& rhs)
{

    ostream << rhs.hours_ << " Hours, " << rhs.minutes_ << " Minutes, "<< rhs.seconds_ << " Seconds"<<std::endl;
    return ostream;
}

//This is in stream operator that prompts user to enter hours, mins and secs.
std::istream& operator>>(std::istream& istream, TimeSpan& rhs) 
{
    double hours, minutes, seconds;
    std::cout << "Enter Hours :  \n" ;
    istream >> hours;
    std::cout << "Enter Minutes  \n:  ";
    istream >> minutes;
    std::cout << "Enter Seconds :  \n";
    istream >> seconds;
    rhs.convert(hours, minutes, seconds);
    return istream;
}

