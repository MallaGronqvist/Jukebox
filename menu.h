// Project
// Malla Grönqvist
// Header file for classes MenuItem and Menu

#ifndef DT019G_MENU_H
#define DT019G_MENU_H

#include <string>
#include <vector>

class MenuItem {
private:
    // Data members
    std::string menuText;
    bool option;

public:
    // Constructors
    MenuItem();
    MenuItem(std::string pMenuText, bool pOption);

    // Member functions
    void setMenuText(std::string pMenuText);
    void setOption(bool pOption);
    std::string getMenuText();
    bool getOption();
};

class Menu {
private:
    // Data members
    std::vector<MenuItem>menuItems;
    std::string menuTitle;

public:
    // Constructor and destructor
    Menu();
    ~Menu();

    // Member functions
    void addItem(std::string pMenuText, bool pOption);
    void setMenuTitle(std::string pMenuTitle);
    void printMenuItems();
    int getMenuChoice();
    void setMenuItemOptions(bool pOption); // Set function for enabling all menu items.
};

#endif //DT019G_MENU_H

