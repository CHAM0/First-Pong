#include <stdio.h>
#include <iostream>
#include <string>


#ifndef CHARACTER_HPP
#define CHARACTER_HPP



class Character {
    
    public:
    void takeDamage (int damage);                                       
    void attack (Character &cible);
    void drinkHealth (int potion);
    void newWeapon (std::string newWeaponName, int newWeaponDamage);
    bool isAlive ();
    void addName (std::string gladiatorName);
    void displayInformation () const;
    
    
    Character(std::string weaponName , int weaponDamage);   // Constructeur sur mesure 
    Character();
    ~Character();
    
  private:
    int m_health;
    int m_stamina;
    std::string m_weaponName;
    int m_weaponDamage;
    std::string m_gladiatorName;

};

#endif // CHARACTER_HPP
