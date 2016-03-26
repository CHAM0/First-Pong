#include <cstdio>
#include <iostream>
#include <string>
#include "Character.hpp"






int main() {

    std::cout<<"#################################################"<<std::endl;  //Introduction
    std::cout<<"###       Bienvenue dans GladiatorDayz !      ###"<<std::endl;
    std::cout<<"###       Le but est de faire survivre        ###"<<std::endl;
    std::cout<<"###       ton gladiateur le plus possible     ###"<<std::endl;
    std::cout<<"#################################################\n"<<std::endl;
    
    std::cout<<"#################################################"<<std::endl;
    std::cout<<"###         Création du glatiateur !          ###"<<std::endl;
    std::cout<<"#################################################\n\n"<<std::endl;
    
    std::cout<<"Entre le nom de ton gladiateur : "<<std::endl;  // Creation du nom du gladiateur
    std::string gladiatorName ("noName");
    std::getline (std::cin,gladiatorName);
    
  
    std::cout<<"\nBienvenue dans l'arène "<<gladiatorName<<"\n\nC'est deja l'heure de ton premier combat"<<std::endl;  //Prologue
    std::cout<<"Pour commencer tu vas devoir choisir une arme !\n"<<std::endl;
    
    
    Character myGladiateur;  // Construction de l'objet MyGladiateur et initialisation de ses attributs
    myGladiateur.setName(gladiatorName);  // Enregistrement du nom du gladiateur dans m_gladiatorName
    
    
        int x = 0;  //Boucle pour choix de l'arme 
       while(x != 1 && x != 2){
        
        std::cout<<"Arme 1 = Glaive    Arme 2 = Masse"<<std::endl;
        std::cout<<"Tappe 1 pour la première arme ou 2 pour la seconde ! "<<std::endl;
        std::cin>>x;
        }
        
        if (x == 1) {
            myGladiateur.setNewWeapon("Glaive",20);
        }
        
        else {
            myGladiateur.setNewWeapon("Masse",20);
        }
     
     std::cout<<"\n#################################################"<<std::endl;  
     std::cout<<"###               COMBAT ARENE 1              ###"<<std::endl;
     std::cout<<"#################################################\n"<<std::endl;
    
    
    Character opponentGladiateur;  // Construction de l'objet opponentGladiateur et initialisation de ses attributs
    std::string opponentName ("Brutus Le Roxxor");  // Création du nom de l'adversaire
    opponentGladiateur.setName(opponentName);  // Enregistrement du nom du gladiateur dans m_gladiatorName
    
    myGladiateur.displayInformation();  // Affichage des informations concernant les combattants
    std::cout<<"\nContre\n"<<std::endl;
    opponentGladiateur.displayInformation();
    
    

return 0;
}
