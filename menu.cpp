// Project
// Malla Grönqvist
// Definition file for classes MenuItem and Menu

#include "menu.h"
#include <iostream>


MenuItem::MenuItem() {
    menuText = "";
    option = false;
}

MenuItem::MenuItem(std::string pMenuText, bool pOption) {
    menuText = pMenuText;
    option = pOption;
}

void MenuItem::setMenuText(std::string pMenuText) {
    menuText = pMenuText;
}

void MenuItem::setOption(bool pOption) {
    option = pOption;
}

std::string MenuItem::getMenuText() {
    return menuText;
}

bool MenuItem::getOption() {
    return option;
}

Menu::Menu() {
    // menuTitle and vector are initiated as empty.
}

Menu::~Menu() {
    // Menu's vector and string are destructed when out of scope.
}

void Menu::addItem(std::string pMenuText, bool pOption) {
    // Declare a menu item and set its data members with function arguments.
    MenuItem tmpMenuItem;
    tmpMenuItem.setMenuText(pMenuText);
    tmpMenuItem.setOption(pOption);
    // Add menu item to the vector.
    menuItems.push_back(tmpMenuItem);
}

void Menu::setMenuTitle(std::string pMenuTitle) {
    menuTitle = pMenuTitle;
}

void Menu::printMenuItems() {
    // Print menu title.
    std::cout << menuTitle << std::endl;
    // Print menu options.
    int optionNumber = 1;
    for (auto idx : menuItems) {
        std::cout << optionNumber << ". " << idx.getMenuText() << std::endl;
        optionNumber++;
    }
}

int Menu::getMenuChoice() {
    bool again = true;
    do {    // Repeat if menu item is not enabled
        int choice;
        std::cout << "Enter your choice from the menu options:" << std::endl;
        std::cin >> choice;  // Read user input into choice.
        std::cin.get();
        int idx = (choice - 1);
        // Check whether menuItem is enabled or not.
        if (menuItems[idx].getOption()) {
            again = false;  // Don't repeat if menu item is enabled
            return choice;  // Return user's choice
        }
        else {
            std::cout << "The menu item is not available. You need to load "
                "the list of albums from file first." << std::endl;
        }
    } while (again);
}

void Menu::setMenuItemOptions(bool pOption) {
    // Set each menu item's option with the function argument.
    // Make menu items available or unavailable to the user.
    for (auto& idx : menuItems) {
        idx.setOption(pOption);
    }
}


