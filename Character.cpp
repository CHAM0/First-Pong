#include "Character.hpp"
#include <cstdio>
#include <iostream>
#include <string>




Character::Character() = default;

Character::Character(std::string weaponName, int weaponDamage) : m_health (100), m_stamina (100), m_weaponName (weaponName), m_weaponDamage (weaponDamage) {
    
}

Character::~Character() {
    
}


void Character::takeDamage( unsigned short int damage) { 

    m_health -= damage;
    
    if ( m_health < 0) {
    
        m_health=0;
    }    
}
 
void Character::attack(Character &cible)const {
    
    cible.takeDamage(m_weaponDamage);
}

void Character::drinkHealth( unsigned short int potion) {
    
    m_health += potion;
    
    if (m_health > 100) {
        
        m_health = 100;
    }
    
}

void Character::setNewWeapon(const std::string newWeaponName, unsigned short int newWeaponDamage) {
    
    m_weaponName = newWeaponName;
    m_weaponDamage = newWeaponDamage;
    
}

bool Character::isAlive() const{
    
    return m_health > 0;
}

void Character::setName(const std::string gladiatorName){
    
    m_gladiatorName = gladiatorName;
}
    
void Character::displayInformation() const {
    
    std::cout<< "Nom du gladiateur : " << m_gladiatorName << "\nArme détenu : " << m_weaponName << "\nDégat de l'arme : " << m_weaponDamage <<"\nPoint de vie : " << m_health << "\nStamina : " << m_stamina <<std::endl;
    
    
}





