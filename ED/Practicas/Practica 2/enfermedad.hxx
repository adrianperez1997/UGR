/** @brief fichero de implementacion de la clase enfermedad

*/


enfermedad::enfermedad(){
  // @todo implementar esta funcion
  name="";
  ID="";
  database="";
}

enfermedad::enfermedad(const std::string & name, const std::string & ID, const std::string & database){
 // @todo implementar esta funcion
	this->name=name;
	this->ID=ID;
	this->database=database;
}
  
//@todo implementar el resto de métodos especificados en enfermedad.h 
 void enfermedad:: setName(const std::string & name){
 	this->name=name;
 }
 void   enfermedad::setID(const std::string & ID){
 	this->ID=ID;
 }
void  enfermedad:: setDatabase(const std::string & database){
 	this->database=database;
 }
 std::string  enfermedad:: getName( ) const{
 	return this->name;
 }
  std::string  enfermedad::getID( ) const{
 	return this->ID;
 }
std::string  enfermedad:: getDatabase( ) const{
 	return this->database;
 }
 enfermedad & enfermedad::operator=(const enfermedad & e){
 	if(this!=&e){
 		this->name=e.name;
 		this->ID=e.ID;
 		this->database=e.database;
 	}
 	return *this;
 }
 std::string  enfermedad:: toString() const {
 	std::string cadena;
 	cadena="Nombre enfermedad:"+name+",ID:"+ID+",datos de la base"+database;
 	return cadena;
 }
 // Operadores relacionales
bool  enfermedad:: operator==(const enfermedad & e) const{
 	bool igual=false;
	 	if(e.name==this->name && e.ID==this->ID && e.database==this->database){
	 		igual=true;		 	
		 }
	return igual;
 } 
 bool  enfermedad::operator!=(const enfermedad & e) const{
 	bool igual=false;
	 	if(e.name!=this->name && e.ID!=this->ID && e.database!=this->database){
	 		igual=true;		 	
		 }
	return igual;
 }
 bool  enfermedad::operator<(const enfermedad & e) const {	//Orden alfabético por campo name. 
 	bool ordenado=false;
 	if(this->name<e.name){
		ordenado=true;
	 }
	return ordenado;
 }
	bool enfermedad::nameContains(const std::string & str) const{
 		bool encontrado=false;
 		//std::size_t found = this->name.find(str);
  		if (this->name.find(str)!=std::string::npos){
			encontrado=true;	
  		}
  		return encontrado;
 	}
 std::ostream& operator<< ( std::ostream& os, const enfermedad & e){
   // @todo implementa esta funcion
     
    os<<"Nombre:"<< e.getName()<<"\n";
	os<<"ID:"<<e.getID()<<"\n";
	os<<"DataBase:"<<e.getDatabase()<<"\n";
	os<<std::endl;
   return os;
 }
   
   
 
