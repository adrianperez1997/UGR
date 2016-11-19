/* 
 * mutacion.h
 * 
 * Copyright  (C) Juan F. Huete y Carlos Cano 
*/
#ifndef __MUTACION_H
#define __MUTACION_H

#include <string>
#include <iostream> 
#include <vector>

#include "enfermedad.h"
//! Clase mutacion, asociada a la definición de una mutación/SNP 
/*! mutacion::mutacion,  .....
 * 
 @todo Implementa esta clase, junto con su documentación asociada
*/

/*
*mutacion representa una clase en la cual vienen definidos varios parametros, los cuales
*deben cumplir las siguientes espedificaciones:
*Pre: ID -> rsXXXX, chr>=1 AND chr<=22 | chr=X,Y, pos>0, ref_alt=cadena de caracteres
*{A,T,G,C}, common=0,1, caf=longitud(ref_alt)|NULL, clnsig={0-7,255}
*/
class mutacion {
 private:
  std::string ID;
  std::string chr; //valido del 1-22 XY
  unsigned int pos; //No puede ser 0
  std::vector<std::string> ref_alt; 
  std::vector<std::string> genes; 
  bool common;
  std::vector<float> caf;//misma longitud q ref_alt o estar� vacio
  std::vector<enfermedad> enfermedades;
  std::vector<int> clnsig;

 public:
  mutacion();
  mutacion(const mutacion& m);
  mutacion(const std::string & str);   //para crear objeto mutacion a partir de la cadena que contiene una línea completa del fichero de entrada
 
  void setID(const std::string & id);
  void setChr(const std::string & chr);
  void setPos(const unsigned int & pos);
  void setRef_alt(const std::vector<std::string> & ref_alt);
  void setGenes (const std::vector<std::string> & genes);  
  void setCommon (const bool & common);
  void setCaf (const std::vector<float> & caf);
  void setEnfermedades (const std::vector<enfermedad> & enfermedades);
  void setClnsig (const std::vector<int> & clnsig);  
  
  std::string getID( ) const;
  std::string getChr( ) const;
  unsigned int getPos( ) const;
  const std::vector<std::string> & getRef_alt () const;
  const std::vector<std::string> & getGenes () const;
  bool getCommon () const;
  const std::vector<float> & getCaf () const;
  const std::vector<enfermedad> & getEnfermedades () const;
  const std::vector<int> & getClnsig () const;
    

  mutacion & operator=(const mutacion & m);
  bool operator==(const mutacion & m) const;
  bool operator<(const mutacion & m) const;      //El orden viene determinado por Chr y pos. El primer criterio es el número de cromosoma. El orden para el número de cromosoma se rige por "1"<"2"<"3"<...<"22"<"X"<"Y"<"MT". Dos mutaciones del mismo cromosoma deben ordenarse según su posición, de menor posición a mayor (orden natural de enteros). 

};

  std::ostream& operator<< ( std::ostream & os , const mutacion & m );   //Imprimir TODOS los campos del objeto mutación.


#include "mutacion.hxx"
#endif
