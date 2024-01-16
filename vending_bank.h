#ifndef VENDING_BANK_H_
#define VENDING_BANK_H_
#include <string>

class VendingBank
{
public:
    VendingBank();

    VendingBank(int pennies, int nickels, int dimes, int quarters, std::string snackName);

    //getters
    int id() const;
    int pennies() const;
    int nickels() const;
    int dimes() const;
    int quarters() const;
    bool isSnackInStock(const std::string& snackName) const;

    //setters
    void SetID(int id);
    void SetCoins(int pennies, int nickels, int dimes, int quarters);
    void SetSnackName(const std::string& snackName);

    //Action
    void addCoin(int value);
    bool changeDisburse(int amount);
    int checkTotalDepositedCoins(int pennies, int nickels, int dimes, int quarters, const std::string& snackName);
    void addSnack(const std::string& snackName, int price);
    void removeSnack(const std::string& snackName);


    //operator overriders declaration
    VendingBank& operator+=(const VendingBank& rhs);
    VendingBank operator+(const VendingBank& rhs) const;
    VendingBank& operator-=(const VendingBank& rhs);
    VendingBank operator-(const VendingBank& rhs) const;
    VendingBank& operator*=(const VendingBank& rhs);
    VendingBank operator*(const VendingBank& rhs) const;
    VendingBank& operator/=(const VendingBank& rhs);
    VendingBank operator/(const VendingBank& rhs) const;

    bool operator==(const VendingBank& rhs) const;
    bool operator!=(const VendingBank& rhs) const;
    
    friend std::ostream& operator<<(std::ostream& stream, const VendingBank& rhs);
    friend std::istream& operator>>(std::istream& stream, VendingBank& rhs);

private:
    const int id_;
    int pennies_;
    int nickels_;
    int dimes_;
    int quarters_;
    std::string snacks_;
};
#endif
