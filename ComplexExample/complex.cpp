//FICHIER SOURCE
#include "complex.h"

/**
 * ! ATTENTION !
 * - La signature d'une méthode doit être la même dans le header (.h) que dans le fichier source (.cpp);
 * - Toutes les méthodes ont un type de retour, sauf les constructeurs et destructeurs; (1)
 * - NomDeClasse:: -> permet d'accéder (afin de pouvoir définir) les méthodes contenues dans la classe NomDeClasse.
 *
 *      (1) void myFunction(int parameter);
 *          ----                              type de retour (2)
 *              ----------                    nom de la fonction
 *                          ---               type du paramètre passé à la fonction
 *                              ---------     nom du paramètre
 *
 *      (2) void :               ne retourne rien -> mutateurs (setters), fonctions d'affichage
 *          int, double, etc :   retourne une élément de type int, double, etc -> accesseurs (getters)
*/

//CONSTRUCTEURS
///par défaut
Complex::Complex() : real(0), imaginary(0)
{
    //Il n'y a rien besoin de mettre ici.
    //Par souci de clareté, pas présenté sous forme inline.
}
///paramétrique
Complex::Complex(double real, double imaginary)
{
    //on accède aux attributs de l'objet courant.
    this->real = real;
    this->imaginary = imaginary;
}
//de recopie
Complex::Complex(const Complex & other)
{
    this->real = other.real;
    this->imaginary = other.imaginary;
}
//de conversion
Complex::Complex(double value)
{
    this->real = this->imaginary = value;
}

//METHODES DE CLASSE
///opération : addition
Complex Complex::add(const Complex & other)
{
    return Complex(this->real + other.real, this->imaginary + other.imaginary);
}
///affichage
void Complex::show()
{
    //si real == 0 : on ne l'affiche pas
    if(this->real != 0)
    {
        cout << this->real;
    }
    //si imaginary == 0 : on ne l'affiche pas
    if(this->imaginary != 0)
    {
        cout << showpos << this->imaginary << "i" << noshowpos;
    }
    if(this->real == 0 && this->imaginary == 0)
    {
        cout << "Empty complex number.";
    }
    //retour à la ligne
    cout << endl;
}

//SURCHARGE D'OPERATEURS
/// +
Complex Complex::operator+(const Complex & other) const
{
    return Complex(this->real + other.real, this->imaginary + other.imaginary);
}
/// =
///remarque générale : la méthode par défaut offerte par le compilateur suffisante car il n'y a pas de pointeur dans cette classe.
Complex & Complex::operator=(const Complex & other)
{
    //si le complexe passé en paramètre est exactement le même que le complex courant, on ne change rien :
    ///remarque : dans ce contexte il n'est évidemment pas très utile, mais au moins vous voyez le concept.
    if(&other == this)
    {
        return *this;
    }

    //on copie les valeurs de l'objet passé en paramètre dans l'objet courant
    ///remarque : on pourrait imaginer faire le test suivant si on a un objet plus compliqué :
    ///           si le réel/imaginaire du complexe passé en paramètre est différent du réel/imaginaire courant, on modifie les paramètres de l'objet courant.
    this->real = other.real;
    this->imaginary = other.imaginary;

    return *this;
}

//SURCHARGE D'OPERATEURS : fonction non-membre amie
/// <<
ostream& operator<<(ostream & os, const Complex & complex)
{
    return os << "("<<complex.real << ", "<< complex.imaginary << "i)" << endl;
}
/// *
Complex operator*(const Complex & c1, const Complex& c2)
{
    return Complex(c1.real - c2.real, c1.imaginary - c2.imaginary);
}

//SURCHARGE D'OPERATEURS : fonction non-membre
Complex operator-(const Complex & x, const Complex & y)
{
    return Complex(x.getReal() - y.getReal(), x.getImaginary() - y.getImaginary());
}