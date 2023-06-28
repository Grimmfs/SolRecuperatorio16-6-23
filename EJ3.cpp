
bool datosInvalidos(string especialidad,unsigned int horaDesde,unsigned int horaHasta, string modeloDeAuto){
	bool noCumpleRequisitos=false;
	if (especialidad==NULL || modeloDeAuto==NULL || horaDesde==NULL || horaHasta== NULL || horaDesde>horaHasta){
		noCumpleRequisitos=true;
	}
	return noCumpleRequisitos;
}

bool stringPerteneceALista(string string,Lista<String*>* listaString ){
	listaString->reiniciarCursor();
	bool perteneceALista=false;
	while(listaString->avanzarCursor() && !perteneceALista){
		if(listaString->obtenerCursor==string){
			perteneceALista=true;
		}

	}
	return perteneceALista;
	
}
bool tieneTurnoDisponible(Lista<Turno*>* turnosDelTaller, unsigned int horaDesdeSolicitada, unsigned  int horaHastaSolicitada){
	bool tieneTurno=false, turnoOcupado, horaDesdeDisponible, horaHastaDisponible; 
	turnosDelTaller->reiniciarCursor();
	 

	Turno* turnoActual;
	while (turnosDelTaller->avanzarCursor() &&  !tieneTurno){
		turnoActual=turnosDelTaller->obtenerCursor();
		horaDesdeDisponible= turnoActual->obtenerHoraDesde() <=horaDesdeSolicitada;
		horaHastaDisponible= turnoActual->obtenerHoraHasta() >=horaHastaSolicitada;
		turnoOcupado=turnoActual->estaOcupado();
		if (horaDesdeDisponible && horaHastaDisponible && !turnoOcupado){
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
bool atiendeEspecialidad, noAceptaModelo, hayTurnoDesocupado;
Lista <Taller*>* talleresConTurnoLibre=new Lista<Taller*>*;
taller* tallerActual;
talleresDisponibles->reiniciarCursor();

while(talleresDisponibles->avanzarCursor()){
	tallerActual=talleresDisponibles->obtenerCursor();
	atiendeEspecialidad=stringPerteneceALista(especialidad,tallerActual->obtenerEspecialidades())
	if (atiendeEspecialidad){
		noAceptaModelo=stringPerteneceALista(tallerActual->modelosNoAtendidos(),modeloDeAuto);
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
					
