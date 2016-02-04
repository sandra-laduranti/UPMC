package serveur;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.LinkedList;
import java.util.List;

public class Serveur {
	
	private static ServerSocket serveur;
	private static Socket socket;
	private static List <Socket> clients;
	private static int NOMBRE_MAX_CLIENTS = 2;
	//private static List <Lecture> pool;
	
	public static void main(String[] args) {
		clients = new LinkedList <Socket>();
		//pool = new LinkedList <Lecture>();
		
		/*for (int i = 0; i < NOMBRE_MAX_CLIENTS; i++) {
			pool.add(new Lecture());
			pool.get(i).start();
		}*/
		
		try {
			serveur = new ServerSocket(55555);
			System.out.println("> Lancement du serveur...");
			
			while(true) {
				socket = serveur.accept();
				if (clients.size() < NOMBRE_MAX_CLIENTS) {
					clients.add(socket);
					new Lecture(socket, clients).start();
				}
				else {
					socket.close();
				}
			}
		} catch (IOException e) {
			System.err.println("> Erreur de lancement du serveur...");
		}
	}
	
}