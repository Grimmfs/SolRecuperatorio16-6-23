
bool datosInvalidos(String especialidad,unsigned int horaDesde,unsigned int horaHastas, string modeloDeAuto){
	bool noCumpleRequisitos=false;
	if (especialidad==NULL || modeloDeAuto==NULL || horaDesde>horaHasta){
		noCumpleRequisitos=true;
	}
	return noCumpleRequisitos;
}

bool stringPerteneceA(string string,Lista<String*>* listaString ){
	listaString->reiniciarCursor();
	bool pertenece=false;
	while(listaString->avanzarCursor() && !pertenece){
		if(listaString->obtenerCursor==string){
			pertenece=true;
		}

	}
	return pertenece;
	
}
bool tieneTurnoDisponible(Lista<Turno*>* turnosDelTaller, unsigned int horaDesde, unsigned  int horaHasta){
	bool tieneTurno=false;
	turnosDelTaller->reiniciarCursor();
	Turno* turnoActual;
	while (turnosDelTaller->avanzarCursor() &&  !tieneTurno){
		turnoActual=turnosDelTaller->obtenerCursor();
		if (turnoActual->obtenerHoraDesde()<=horaDesde && turnoActual->obtenerHasta>=horaHasta){
			tieneTurno=true;
		}

	}
	return tieneTurno;
}



Lista <Taller*>* buscarTallerConTurnoLibre(Cola<Taller*>* talleresDisponibles, string especialidad,
					    unsigned int horaDesde,unsigned int horaHastas, string modeloDeAuto){
if (datosInvalidos(especialidad,horaDesde,horaHasta,modeloDeAuto)){
	throw "datos Invalidos."
}
bool cumpleEspecialidad,aceptaModelo,turnoDesocupado;
Lista <Taller*>* talleresConTurnoLibre=new Lista<Taller*>*;
taller* tallerActual;
talleresDisponibles->reiniciarCursor;

while(talleresDisponibles->avanzarCursor()){
	tallerActual=talleresDisponibles->obtenerCursor();
	atiendeEspecialidad=stringPerteneceA(especialidad,tallerActual->obtenerEspecialidades())
	if (atiendeEspecialidad){
		noAceptaModelo=stringPerteneceA(tallerActual->modelosNoAtendidos(),modeloDeAuto);
		if (!noAceptaModelo){
			hayTurnoDesocupado=tieneTurnoDisponible(tallerActual->obtenerTurnos(),horaDesde,horaHasta);
			if (hayTurnoDesocupado){
				talleresConTurnoLibre->add(tallerActual);
				}
			}
		}
	}
	return talleresConTurnoLibre;
}
					
