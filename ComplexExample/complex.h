//HEADER
#ifndef COMPLEX_H
#define COMPLEX_H

//l'avantage de tout inclure ici c'est que ça ne sera fait qu'une fois (par classe)
#include <iostream> //stream et compagnie
#include <iomanip>  //setfill, no/showpos, ...

//permet d'utiliser des éléments de la bibliothèque standard de C++    (en français on utilise le mot "bibliothèque" et non "libraire")
using namespace std;

//CLASS
class Complex
{
    public:
        //CONSTRUCTEURS -> les constructeurs n'ont pas de type de retour (void, int, double, ...).
        ///par défaut : Si on ne déclare pas d'autre constructeur, il est appelé automatiquement sans avoir besoin d'être déclaré dans l'objet.
        ///             Par contre, si d'autres constructeurs sont déclarés dans la classe, il doit être déclaré aussi (comme ici).
        Complex();
        ///paramétrique
        Complex(double real, double imaginary);
        //de recopie
        Complex(const Complex & other);
        //de conversion
        Complex(double value);

        //DESTRUCTEUR :
        ///             Tout comme pour le constructeur par défaut, il est appelé automatiquement sans avoir besoin d'être déclaré dans l'objet.
        ///             Si on a des attributs qui se présentent sous forme de pointeur, il faut le préciser dans le destructeur.
        ///             Comme ici on n'utilise pas de pointeur, on peut le laisser vide (voire ne pas le déclarer du tout).
        ~Complex() {}

        //METHODES DE CLASSE
        ///accesseurs : inline  -> pratique quand il n'y pas grand chose entre les accolades
        double getReal() const { return real; }
        double getImaginary() const { return imaginary; }
        ///mutateurs : inline
        void setReal(double real ){ this->real = real; }
        void setImaginary(double imaginary) { this->imaginary = imaginary; }
        ///opération : addition
        Complex add(const Complex & other);
        ///affichage
        void show();

        //SURCHARGE D'OPERATEURS : fonctions membres
        /// +
        Complex operator+(const Complex & other) const;
        /// =
        Complex & operator=(const Complex & other);

        //SURCHARGE D'OPERATEURS : fonctions non-membres amies
        /// <<
        friend ostream& operator<<(ostream & os, const Complex & other);
        /// *
        friend Complex operator*(const Complex & c1, const Complex & c2);

    private:
        //ATTRIBUTS privés :
        ///Ne sont pas accessibles depuis l'extérieur de la classe, à moins d'utiliser une fonction amie
        double real;
        double imaginary;
};

//SURCHARGE D'OPERATEURS : fonctions non-membres
Complex operator-(const Complex & x, const Complex & y);

#endif // COMPLEX_H
