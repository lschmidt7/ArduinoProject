
import auxiliar.Cliente;
import java.awt.List;
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
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
public class Server {
    
    ArrayList<Car> cars = new ArrayList<Car>();
    ArrayList<Socket> sockets = new ArrayList<Socket>();
    
    Traffic t = new Traffic();

    public Server() {

    }
    
    // Add um novo socket
    public void add(Car c){
        cars.add(c);
    }
    
    public void init(){
        for(Car a : cars){
            try {
                Socket s = new Socket(a.ip,a.port);
                sockets.add(s);
                ListeningCar lc = new ListeningCar(s, a);
                lc.start();
            } catch (IOException ex) {
                Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
    
    public void send(String command, Socket s){
        BufferedReader buffer = new BufferedReader( new InputStreamReader(System.in));
        DataOutputStream outToServer;
        try {
            outToServer = new DataOutputStream(s.getOutputStream());
            outToServer.writeBytes(command + '\0');
        } catch (IOException ex) {
            Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    private class ListeningCar extends Thread{
        
        Car c;
        Socket s;
        BufferedReader buffer;
        String msg;
        
        public ListeningCar(Socket s, Car c){
            this.s = s;
            this.c = c;
        }
        
        public void run(){
            while(true){
                try {
                    buffer = new BufferedReader(new InputStreamReader(s.getInputStream()));
                    msg = buffer.readLine();
                    
                    System.out.println("MSG : "+msg);
                    
                    if(msg.equals(P2C.ORDER_PASS)){
                        t.add(c,s);
                        if(t.isEmpty()){
                            t.freeFirst();
                            send(P2C.FREE,s);
                        }
                    }
                    
                    if(msg.equals(P2C.ORDER_EXIT)){
                        t.pop();
                        if(!t.isEmpty()){
                            t.freeFirst();
                            send(P2C.FREE,t.getFirst());
                        }
                    }
                    
                } catch (IOException ex) {
                    Logger.getLogger(Cliente.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        }
        
    }
}
