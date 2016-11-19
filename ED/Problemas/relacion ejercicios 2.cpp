/*
 * Relacion de ejercicios 2, Estructura de datos 
 * Autor: Adrian Perez Ortega
 * Fecha de entrega 15/11/2016
 */

// EJERCICIO 1

void ejercicio1(stack<int> &pila, int x, int y){
	stack<int> pilaAux;
	while(!pila.empty()){
		if(pila.top()==x){
			pilaAux.push(y);
		else { pilaAux.push(pila.top()); }
		pila.pop();
	}
	
	while(!pilaAux.empty()){
		pila.push(pilaAux.top());
		pilaAux.pop();
	}
}


// EJERCICIO 2


bool ejercicio2(const string &parentesis){
	int izquierda=0, derecha=0;
	for(int i=0; i<parentesis.size(); i++){
		if(parentesis[i]=='('){
			izquierda++;
		}
		if(parentesis[i]==')'){
			derecha++;
			if(izquierda<derecha)
				return false;
		}
	}
	return izquierda==derecha;
}


// EJERCICIO 3


template<typename T>
class ejercicio3{
	stack<T> cola, aux;
	
	int size(){
		return cola.size();
	}
	
	bool empty(){
		return cola.empty();
	}	
	
	void push(T el){
		cola.push(el);
	}
	
	void pop(){
		while(!cola.empty()){
			aux.push(cola.top());
			cola.pop();
		}
		
		aux.pop();
		while(!aux.empty()){
			cola.push(aux.top());
			aux.pop();
		}
	}
	
	void erase(){
		while(!cola.empty()){
			cola.pop();
		}
	}	
}

// EJERCICIO 4

template<typename T>
class ejercicio4{
	queue<T> pila, aux;
	
	bool empty(){
		return pila.empty();
	}	
	
	int size(){
		return pila.size();
	}
	
	void push(T el){
		pila.push(el);
	}
	
	void pop(){
		int i=0;
		while(!pila.empty()){
			if(i!=pila.size()-1)
				aux.push(pila.front());
			
			pila.pop();
			
			i++;
		}
		
		while(!aux.empty()){
			pila.push(aux.front());
			aux.pop();
		}
	}
	
	T top(){
		return pila.back();
	}
}

// EJERCICIO 5

int ijercicio5(string expresion){
	stack<int> v;
	int dcha, izq;
	for(int i=0; i!=expresion.size(); ++i){
		if(expresion[i]>='0' && expresion[i]<='9'){
			v.push((int)expresion[i]-(int)'0');
		}
		else if(expresion[i]!=' '){
			dcha= v.top();
			v.pop();
			izq= v.top();
			v.pop();
			if(expresion[i]='+')
				v.push(izq+dcha);
				
			if(expresion[i]='-')
				v.push(izq-dcha);
				
			if(expresion[i]='*')
				v.push(izq*dcha);
				
			if(expresion[i]='/')
				v.push(izq/dcha);
				
			if(expresion[i]='^')
				v.push(pow(izq, dcha));
		}
	}
	return v.top();
}


// EJERCICIO 7

void ejercicio7(stack<int> &pila, int pos, int x){
	stack<int> aux;
	for(int i =0; i<pos; i++){
		aux.push(pila.top());
		pila.pop;
	}
	pila.push(x);
	while(!aux.empty()){
		pila.push(aux.top());
		aux.pop;
	}
}

// EJERCICIO 8

void ejercicio8(queue<int> &cola, int pos, int x){
	queue<int> aux;
	for(int i=0; i<pos; i++){
		aux.push(cola.front());
		aux.pop();
	}
	cola.push(x);
	while(!cola.empty()){
		aux.push(cola.front());
		cola.pop();
	}
	cola=aux;
}

// EJERCICIO 10

bool ejercicio9(const string &s){
	stack<char> pila;
	queue<char> cola;
	bool resultado=true
	for(unsigned i=0; i<s.size(); i++){
		if(s[i]!=' '){
			pila.push(s[i]);
			cola.push(s[i]);
		}
	}
	
	for(unsigned j=0; j<s.size()/2 && resultado; j++){
		if(pila.top()!=cola.front())
			resultado=false;
		pila.pop();
		cola.pop();
	}
	return resultado;
}

// EJERCICIO 11

struct ejercicio11{
	string apellidos, nombre;
	int prioridad;
};

bool operator<(const ejercicio11 &d1, const ejercicio11 &d2){
	return d1.prioridad<d2.prioridad;
}

