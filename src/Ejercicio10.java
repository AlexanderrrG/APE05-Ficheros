import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;
 
// clase entidad
class Usuario {
    String id;
    String nombre;
    int edad;
 
    public Usuario(String id, String nombre, int edad) {
        this.id = id;
        this.nombre = nombre;
        this.edad = edad;
    }
}
 
// clase principal y gestor CRUD
public class Ejercicio10 {
    private static final String ARCHIVO = "usuarios.txt";
    private Scanner scanner = new Scanner(System.in);
 
    // metodo para leer archivo y pasarlo a memoria
    private ArrayList<Usuario> cargarDatos() {
        ArrayList<Usuario> lista = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(ARCHIVO))) {
            String linea;
            while ((linea = br.readLine()) != null) {
                String[] datos = linea.split(",");
                if (datos.length == 3) {
                    lista.add(new Usuario(datos[0], datos[1], Integer.parseInt(datos[2])));
                }
            }
        } catch (IOException e) {
        }
        return lista;
    }
 
    // metodo para reescribir todo el archivo
    private void guardarTodos(ArrayList<Usuario> lista) {
        try (PrintWriter pw = new PrintWriter(new FileWriter(ARCHIVO))) {
            for (Usuario u : lista) {
                pw.println(u.id + "," + u.nombre + "," + u.edad);
            }
        } catch (IOException e) {
            System.out.println("Error al guardar archivo.");
        }
    }
 
    public void crear() {
        System.out.print("Ingrese ID: ");
        String id = scanner.nextLine();
        System.out.print("Ingrese Nombre: ");
        String nombre = scanner.nextLine();
        
        int edad = 0;
        do {
            System.out.print("Ingrese Edad (> 0): ");
            try {
                edad = Integer.parseInt(scanner.nextLine());
            } catch (NumberFormatException e) {
                edad = 0;
            }
        } while (edad <= 0);
 
        // añadir al archivo
        try (PrintWriter pw = new PrintWriter(new FileWriter(ARCHIVO, true))) {
            pw.println(id + "," + nombre + "," + edad);
            System.out.println("Usuario guardado.");
        } catch (IOException e) {
            System.out.println("Error de escritura.");
        }
    }
 
    public void leer() {
        ArrayList<Usuario> lista = cargarDatos();
        if (lista.isEmpty()) {
            System.out.println("No hay registros.");
            return;
        }
        System.out.println("\n--- LISTA DE USUARIOS ---");
        for (Usuario u : lista) {
            System.out.println("ID: " + u.id + " | Nombre: " + u.nombre + " | Edad: " + u.edad);
        }
    }
 
    public void actualizar() {
        System.out.print("Ingrese ID a actualizar: ");
        String idBuscar = scanner.nextLine();
        
        ArrayList<Usuario> lista = cargarDatos();
        bool encontrado = false;
 
        for (Usuario u : lista) {
            if (u.id.equals(idBuscar)) {
                System.out.print("Nuevo Nombre: ");
                u.nombre = scanner.nextLine();
                do {
                    System.out.print("Nueva Edad (> 0): ");
                    u.edad = Integer.parseInt(scanner.nextLine());
                } while (u.edad <= 0);
                encontrado = true;
                break;
            }
        }
 
        if (encontrado) {
            guardarTodos(lista);
            System.out.println("Usuario actualizado exitosamente.");
        } else {
            System.out.println("ID no encontrado.");
        }
    }
 
    public void eliminar() {
        System.out.print("Ingrese ID a eliminar: ");
        String idBuscar = scanner.nextLine();
        
        ArrayList<Usuario> lista = cargarDatos();
        boolean eliminado = lista.removeIf(u -> u.id.equals(idBuscar));
 
        if (eliminado) {
            guardarTodos(lista);
            System.out.println("Usuario eliminado.");
        } else {
            System.out.println("ID no encontrado.");
        }
    }
 
    public void iniciar() {
        int opcion = 0;
        do {
            System.out.println("\n=== SISTEMA CRUD ===");
            System.out.println("Desarrollador: Alejandro");
            System.out.println("1. Crear");
            System.out.println("2. Leer");
            System.out.println("3. Actualizar");
            System.out.println("4. Eliminar");
            System.out.println("5. Salir");
            System.out.print("Opcion: ");
            
            try {
                opcion = Integer.parseInt(scanner.nextLine());
            } catch (Exception e) {
                opcion = 0;
            }
 
            switch (opcion) {
                case 1: crear(); break;
                case 2: leer(); break;
                case 3: actualizar(); break;
                case 4: eliminar(); break;
                case 5: System.out.println("Saliendo..."); break;
                default: System.out.println("Opcion invalida.");
            }
        } while (opcion != 5);
    }
 
    public static void main(String[] args) {
        Ejercicio10 app = new Ejercicio10();
        app.iniciar();
    }
}