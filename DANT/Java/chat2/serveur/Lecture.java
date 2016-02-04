package serveur;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.List;

public class Lecture extends Thread {
	
	private Socket socket;
	private Ecriture ecriture;
	private InputStream is;
	private InputStreamReader isr;
	private BufferedReader br;
	private List <Socket> clients;
	
	public Lecture() { }
	
	public Lecture(Socket socket, List <Socket> clients) {
		this.socket = socket;
		this.clients = clients;
		this.ecriture = new Ecriture(socket, clients);
	}
	
	/*public void setLecture(Socket socket, List <Socket> clients) {
		this.socket = socket;
		this.clients = clients;
		this.ecriture = new Ecriture(socket, clients);
	}*/

	@Override
	public void run() {
		
		try {
			this.wait();
		} catch (InterruptedException e1) {
			e1.printStackTrace();
		}
		
		String message;
		try {
			this.is = this.socket.getInputStream();
			this.isr = new InputStreamReader(this.is);
			this.br = new BufferedReader(this.isr);
			
			while(true) {
				message = this.br.readLine();
				if (message == null) { // Deconnexion d'un client
					this.clients.remove(this.socket);
					this.socket.close();
					System.out.println("> Deconnexion d'un client...");
					break;
				}
				else {
					this.ecriture.envoyerClient(message);
					System.out.println("Client > " + message);
				}
			}
		} catch (IOException e) {
			System.err.println("> Erreur de lecture sur le serveur...");
		}
	}

}
