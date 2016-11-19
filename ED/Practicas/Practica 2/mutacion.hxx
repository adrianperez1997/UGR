/** @brief fichero de implementacion de la clase mutacion

*/
 
  mutacion::mutacion(){
  	this->chr=1;
  	this->pos=1;
  }
  mutacion::mutacion(const mutacion& m){
  	this->ID=m.ID;
  	this->chr=m.chr;
  	this->pos=m.pos;
  	this->ref_alt=m.ref_alt;
  	this->genes=m.genes;
  	this->common=m.common;
  	this->caf=m.caf;
  	this->enfermedades=m.enfermedades;
  	this->clnsig=m.clnsig;
  	
  }
  mutacion::mutacion(const std::string & str){ //para crear objeto mutacion a partir de la cadena que contiene una línea completa del fichero de entrada
    //Cromosoma
	std::size_t found = str.find("	");
    this->chr = str.substr(0,found);
    //Posicion
    std::size_t found2=str.find("	",found+1);
	std::string post= str.substr(found+1,found2-found-1); //pasar de string a int con stoi
//	std::cerr<<post;
	this->pos=std::stoi(post);
	//ID 
	std::size_t found3=str.find("	",found2+1);
	this->ID = str.substr (found2+1,found3-found2-1);
	//ref_alt
	std::size_t found4=str.find("	",found3+1);
	this->ref_alt.push_back(str.substr (found3+1,found4-found3-1));
	std::size_t found5=str.find("	",found4+1);
	this->ref_alt.push_back(str.substr (found4+1,found5-found4-1));
	//Comun
	std::size_t Common=str.find("COMMON=");
	if(Common!=std::string::npos){
		std::string numero=str.substr(Common+7,1);
		if(numero[0]=='1'){
			common=true;
		}
		else{	
			common=false;
		}
	}
	else{
		common=false;
		}
	//Caf
	std::size_t caaf=str.find("CAF=");
	if(caaf!=std::string::npos){
		std::size_t punto_coma_Caf=str.find(";",caaf);
		std::string str12=str.substr(caaf+4,punto_coma_Caf-caaf-4);
		std::size_t coma=str12.find(",");
		this->caf.push_back(std::stof(str12.substr(0,coma))); //Pasar string a float con stof
		int saltar=0; 
		while(str12[coma+1+saltar]=='.' || str12[coma+1+saltar]==','){
		saltar++;
		}
		this->caf.push_back(std::stof(str12.substr(coma+1+saltar,str12.size()-coma-1-saltar)));	
	}
	else{
		this->caf.push_back(0.0);
		this->caf.push_back(0.0);
	}

	//Gen
	std::size_t gen=str.find("GENEINFO=");
	std::size_t punto_comaGen=str.find(";", gen);
	std::string cadena_genes=str.substr(gen+9, punto_comaGen-gen-9);
	int indicador=0;

	for(int i=0; i < cadena_genes.size(); i++){
		if(cadena_genes.at(i)=='|' || i==(cadena_genes.size()-1)){			
			genes.push_back(cadena_genes.substr(indicador, i+1));
			indicador=i+1;	
		}	
	}

	// ENFERMEDAD NAME
	std::size_t Name=str.find("CLNDBN=");
	std::size_t punto_comaName=str.find(";", Name);
	std::string cadena_name=str.substr(Name+7, punto_comaName-Name-7);

	int contador=0;
	indicador=0;
	
	for(int i=0; i < cadena_name.size(); i++){
		if(cadena_name.at(i)=='|' || cadena_name.at(i)==',' || i==(cadena_name.size()-1)){			
			enfermedad e;
			enfermedades.push_back(e);
			enfermedades.at(contador).setName(cadena_name.substr(indicador, i+1));
			contador++;
			indicador=i+1;	
		}
	
	}

	// ENFERMEDAD ID
	std::size_t id=str.find("CLNDSDBID=");
	std::size_t punto_comaID=str.find(";", id);
	std::string cadena_ID=str.substr(id+10, punto_comaID-id-10);

	contador=0;
	indicador=0;
	for(int i=0; i < cadena_ID.size(); i++){
		if(cadena_ID.at(i)=='|' || cadena_ID.at(i)==',' || i==(cadena_ID.size()-1)){
			enfermedades.at(contador).setID(cadena_ID.substr(indicador, i+1));
			contador++;
			indicador=i+1;	
		}
	}

	// ENFERMEDAD BASENAME
	std::size_t BaseName=str.find("CLNDSDB=");
	std::size_t punto_comaBaseName=str.find(";", BaseName);
	std::string cadena_BaseName=str.substr(BaseName+8, punto_comaBaseName-BaseName-8);

	contador=0;
	indicador=0;
	for(int i=0; i < cadena_BaseName.size(); i++){
		if(cadena_BaseName.at(i)=='|' || cadena_BaseName.at(i)==',' || i==(cadena_BaseName.size()-1)){
			enfermedades.at(contador).setDatabase(cadena_BaseName.substr(indicador, i+1));
			contador++;
			indicador=i+1;	
		}
	}	
	//Clnsing
	std::size_t poscln=str.find("CLNSIG=",0);
	std::size_t posclnfinal=str.find(";", poscln);
	std::string cln=str.substr(poscln+7, posclnfinal-poscln-7);
	
	int contador_cln=0;
	int puntero=0;

	for(int i=0; i < cln.size(); i++){
		if(cln.at(i)=='|' || cln.at(i)==',' || i==(cln.size()-1)){
			int cl = std::stoi(cln.substr(puntero, i+1));
			clnsig.push_back(cl);
			contador_cln++;
			puntero=i+1;	
		}
	}
  }
  
  void mutacion::setID(const std::string & id){
  	this->ID=id;
  }
	void mutacion::setChr(const std::string & chr){
  	this->chr=chr;
  }
    void mutacion::setPos(const unsigned int & pos){
  	this->pos=pos;
  }
    void mutacion::setRef_alt(const std::vector<std::string> & ref_alt){
  	this->ref_alt=ref_alt;
  }
    void mutacion::setGenes (const std::vector<std::string> & genes){
  	this->genes=genes;
  }
    void mutacion::setCommon (const bool & common){
  	this->common=common;
  }
	void mutacion::setCaf (const std::vector<float> & caf){
  	this->caf=caf;
  }
  void mutacion::setEnfermedades (const std::vector<enfermedad> & enfermedades){
  	this->enfermedades=enfermedades;
  }
 void mutacion::setClnsig (const std::vector<int> & clnsig){
  	this->clnsig=clnsig;
  }
  
  std::string mutacion::getID( ) const{
  	return this->ID;
  }
  std::string mutacion:: getChr( ) const{
  	return this->chr;
  }
  unsigned int mutacion::getPos( ) const{
  	return this->pos;
  }
  const std::vector<std::string> & mutacion:: getRef_alt () const{
  	return this->ref_alt;
  }
  const std::vector<std::string> &  mutacion:: getGenes () const{
  	return this->genes;
  }
  bool mutacion::getCommon () const{
  	return this->common;
  }
 const std::vector<float> & mutacion:: getCaf () const{
  	return this->caf;
  }
 const std::vector<enfermedad> & mutacion:: getEnfermedades () const{
  	return this->enfermedades;
  }
const std::vector<int> & mutacion:: getClnsig () const{
  	return this->clnsig;
  }
   mutacion & mutacion:: operator=(const mutacion & m){
    if(this!=&m){
  		this->ID=m.ID;
  		this->chr=m.chr;
  		this->pos=m.pos;
  		this->ref_alt=m.ref_alt;
  		this->genes=m.genes;
  		this->common=m.common;
  		this->caf=m.caf;
  		this->enfermedades=m.enfermedades;
  		this->clnsig=m.clnsig;
  	}
  	return *this;
  }
 bool  mutacion::operator==(const mutacion & m) const{
  	bool igual=false;
	if(this->chr == m.getChr() && this->pos == m.getPos()){
		igual=true;
	}
	return igual;
  }

  bool mutacion::operator<(const mutacion & m) const{
	bool menor;
	if(this->chr != m.getChr()){
		if(this->chr.at(0) >='0' && this->chr.at(0) <= '9'){
			if(m.getChr().at(0) >= '0' && m.getChr().at(0) <= '9')
				menor=this->chr < m.getChr();
			else
				menor=true;
		}
		else if (this->chr.at(0) =='X' && this->chr.at(0) == 'Y'){
			if(m.getChr()=="MT")
				menor=true;
			else
				menor=this->chr < m.getChr();
				
		}
		else
			menor=false;

	}
	else
		menor= this->pos < m.getPos();

	return menor;
}
  
  
   std::ostream& operator<< ( std::ostream & os, const mutacion & m){   //Imprimir TODOS los campos del objeto mutación.
	os << " ID: " << m.getID() << "\n";
	os << " chr: " << m.getChr() << "\n";
	os << " pos: " << m.getPos() << "\n";
	os << " ref_alt: ";
	for (int j=0 ; j<m.getRef_alt().size(); j++)
		os << m.getRef_alt().at(j);
	
	os << "\n genes: ";
	for (int j=0 ; j<m.getGenes().size(); j++)
		os << m.getGenes().at(j);
		
	os << "\n common: ";
	if(m.getCommon())
		os << " true \n";
	else
		os << "false \n";

	os << " caf: ";
	for (int j=0 ; j<m.getCaf().size(); j++)
		os << m.getCaf().at(j);
	
	os << "\n clnsig: ";
	for (int j=0 ; j<m.getClnsig().size(); j++)
		os << m.getClnsig().at(j);
	
	os << "\n enfermedades: ";
	for (int j=0 ; j<m.getEnfermedades().size(); j++)
		os << m.getEnfermedades().at(j);

	
	os << std::endl;
return os;
}

