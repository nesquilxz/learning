package com.carlosribeiro.projeto02;

import com.carlosribeiro.projeto02.model.Empregado;
import corejava.Console;

import java.util.ArrayList;

public class Principal {
    public static void main(String[] args) {
        // ==>

        final int TAM = Console.readInt("Informe o tamanho da lista: "); //constantes em JAVA tudo com letra maiuscula (final).
        ArrayList listaDeEmpregados = new ArrayList(TAM); //criar um vetor. ArrayList é uma classe.

        String nome;
        double salario;
        Empregado umEmpregado;

        boolean continua = true;
        while (continua) {
            System.out.println("\nO que você deseja fazer?");
            System.out.println('\n' + "1. Cadastrar um empregado");
            System.out.println("2. Alterar um empregado");
            System.out.println("3. Remover um empregado");
            System.out.println("4. Listar relação de empregados");
            System.out.println("5. Sair");

            int opcao = Console.readInt('\n' + "Digite um número entre 1 e 5:");

            switch (opcao) {
                case 1:
                    nome = Console.readLine("Informe o nome: ");
                    salario = Console.readDouble("Informe o salário: ");

                    umEmpregado = new Empregado(nome, salario);
                    listaDeEmpregados.add(umEmpregado); //arraylist é uma classe, logo ela tem métodos
                    System.out.println("Empregado adicionado com sucesso!");

                //variavel estatica fica na classe, variavel de instancia fica no objeto
                    //ex: String nome -> de cada objeto, static int quantidade -> da classe.
                    break;
                case 2:

                    break;
                case 3:

                    break;
                case 4:

                    for(int i = 0; i < listaDeEmpregados.size(); i++) {
                        umEmpregado = (Empregado) listaDeEmpregados.get(i);
                        System.out.println(umEmpregado);
                    }

                    break;
                case 5:
                    continua = false;
                    break;
                default:
                    System.out.println('\n' + "Opção inválida!");
                    break;
            }
        }
    }
}
