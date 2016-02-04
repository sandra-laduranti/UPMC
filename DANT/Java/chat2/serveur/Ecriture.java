package serveur;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.util.List;

public class Ecriture extends Thread {
	
	private Socket socket;
	private List <Socket> clients;
	private OutputStream os;
	private OutputStreamWriter osw;
	private BufferedWriter bw;
	
	public Ecriture(Socket socket, List <Socket> clients) {
		this.socket = socket;
		this.clients = clients;
	}

	public void envoyerClient(String texte) {
		if (!this.socket.isClosed()) {
			for (int i = 0; i < clients.size(); i++) {
				if(clients.get(i) != this.socket) {
					try {
						this.os = clients.get(i).getOutputStream();
						this.osw = new OutputStreamWriter(os);
						this.bw = new BufferedWriter(osw);
						
						bw.write(texte);
						bw.newLine();
						bw.flush();
					}
					catch (IOException e) {
						System.err.println("> Erreur d'envoi au(x) client(s)...");
					}
				}	
			}
		}
	}

}
