
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Leonardo
 */
public class Cliente {
    
    private String ipserver = "";
    private int port = 8090;
    private Socket clientSocket = null;
    private String msg;
    
    public Cliente(String ipserver, int port) {
        this.ipserver = ipserver;
        this.port = port;
        try {
            clientSocket = new Socket("192.168.0.104", 8090);
            ListeningMsg lm = new ListeningMsg();
            lm.start();
        } catch (IOException ex) {
            Logger.getLogger(Cliente.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public String getIpserver() {
        return ipserver;
    }

    public void setIpserver(String ipserver) {
        this.ipserver = ipserver;
    }

    public int getPort() {
        return port;
    }

    public void setPort(int port) {
        this.port = port;
    }
    
    private class ListeningMsg extends Thread{
        BufferedReader inFromServer;
        public void run(){
            while(true){
                try {
                    inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                    msg = inFromServer.readLine();
                    System.out.println("MSG: "+msg);
                } catch (IOException ex) {
                    Logger.getLogger(Cliente.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        }
    }
    
}
