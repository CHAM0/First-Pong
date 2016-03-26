#include <cstdio>
#include <iostream>
#include <string>


#ifndef CHARACTER_HPP
#define CHARACTER_HPP



class Character {
    

        
    public:
    
    Character();
    Character(std::string weaponName , int weaponDamage);   // Constructeur sur mesure 
    ~Character();
    
    void takeDamage ( unsigned short int damage);                                       
    void attack (Character &cible) const;
    void drinkHealth (unsigned short int potion);
    void setNewWeapon (const std::string newWeaponName, unsigned short int newWeaponDamage);
    bool isAlive () const;
    void setName (const std::string gladiatorName);
    void displayInformation () const;
    
    
    

    
  private:
    unsigned short int m_health = 100;
    unsigned short int m_stamina = 100;
    std::string m_weaponName = "noName";
    unsigned short int m_weaponDamage = 0;
    std::string m_gladiatorName = "noName";

};

#endif // CHARACTER_HPP

