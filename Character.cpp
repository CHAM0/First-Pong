#include "Character.hpp"
#include <stdio.h>
#include <iostream>
#include <string>




Character::Character() : m_health (100), m_stamina (100), m_weaponName ("Baton en bois"), m_weaponDamage (10) {   //constructeur par default
  
}

Character::Character(std::string weaponName, int weaponDamage) : m_health (100), m_stamina (100), m_weaponName (weaponName), m_weaponDamage (weaponDamage) {
    
}

Character::~Character() {
    
}


void Character::takeDamage(int damage) { 

    m_health -= damage;
    
    if ( m_health < 0) {
    
        m_health=0;
    }    
}
 
void Character::attack(Character &cible) {
    
    cible.takeDamage(m_weaponDamage);
}

void Character::drinkHealth(int potion) {
    
    m_health += potion;
    
    if (m_health > 100) {
        
        m_health = 100;
    }
    
}

void Character::newWeapon(std::string newWeaponName, int newWeaponDamage) {
    
    m_weaponName = newWeaponName;
    m_weaponDamage = newWeaponDamage;
    
}

bool Character::isAlive() {
    
    return m_health > 0;
}

void Character::addName(std::string gladiatorName){
    
    m_gladiatorName = gladiatorName;
}
    
void Character::displayInformation() const {
    
    std::cout<< "Nom du gladiateur : " << m_gladiatorName << "\nArme détenu : " << m_weaponName << "\nDégat de l'arme : " << m_weaponDamage <<std::endl;
    std::cout<<"Point de vie : " << m_health << "\nStamina : " << m_stamina <<std::endl;
    
}



