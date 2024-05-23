#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"

using namespace std;

class Estudiante {
private:
	int id = 0;
	int codigo = 0;
	string nombres, apellidos, direccion, fecha_nacimiento;
	int telefono = 0, id_tipo_sangre = 0;

	//constructor
public:
	Estudiante() {}

	Estudiante(int codi, string nomb, string apel, string dire, int tele, string fn, int id_tsa, int i) {
		id = i;
		codigo = codi;
		nombres = nomb;
		apellidos = apel;
		direccion = dire;
		telefono = tele;
		fecha_nacimiento = fn;
		id_tipo_sangre = id_tsa;
	};

	void setId(int i) { id = i; }
	void setCodigo(int codi) { codigo = codi; }
	void setNombres(string nomb) { nombres = nomb; }
	void setApellidos(string apel) { apellidos = apel; }
	void setDireccion(string dire) { direccion = dire; }
	void setTelefono(int tele) { telefono = tele; }
	void setFecha_Nacimiento(string fn) { fecha_nacimiento = fn; }
	void setId_Tipo_Sangre(int id_tsa) { id_tipo_sangre = id_tsa; }

	int getId() { return id; }
	int getCodigo() { return codigo; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getFecha_Nacimiento() { return fecha_nacimiento; }
	int getId_Tipo_Sangre() { return id_tipo_sangre; }

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string c = to_string(codigo);
		string t = to_string(telefono);
		string tsa = to_string(id_tipo_sangre);

		if (cn.getConectar()) {
			string insertar =
				"INSERT INTO estudiante(codigo,nombres,apellidos,direccion,telefono,fecha_nacimiento, id_tipo_sangre) VALUES('" + c + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + ",'" + tsa + "')';";
			const char* i = insertar.c_str();
			//ejecutar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso de Datos Exitosos..." << endl;
			}
			else {
				cout << "Error al ingresar los Datos " << endl;
			}
		}
		else {
			cout << "xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string consulta = "select * from estudiante";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "---------------------Estudiantes --------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << ":" << fila[1] << ":" << fila[2] << ":" << fila[3] << ":" << fila[4] << ":" << fila[5] << ":" << fila[6] << ":" << fila[7] << endl;
				}
			}
			else {
				cout << "Error al consultar" << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}

	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string cod = to_string(id);
		string tel = to_string(id);
		string tesa = to_string(id);
		string ii = to_string(id);
		if (cn.getConectar()) {
			string actualizar = "update estudiante set codigo = '" + cod
				+ "', nombres='" + nombres + "', apellidos = '" + apellidos + "', direccion= '" +
				direccion + "', telefono= '" + tel + "', fecha_nacimiento = '" + fecha_nacimiento + "', id_tipo_sangre= '" + tesa + "' where id_estudiante = " + ii + "";
			const char* i = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Actualizacion de Datos Exitosa" << endl;
			}
			else {
				cout << "Error al actualizar Datos..." << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}

	void borrar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string ii = to_string(id);
		if (cn.getConectar()) {
			string borrar = "delete from estudiante where id_estudiante = " + ii + "";
			const char* i = borrar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminacion exitosa..." << endl;
			}
			else {
				cout << "Error al ingresar" << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}

};

