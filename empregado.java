package com.pedrohenriques.projeto01.model;

public class Empregado {
    private String nome; //string é uma classe, nao é primitivo (letra minuscula).
    private double salario;
    private static String telefone = "22223333"; //static é um valor aderido a propria classe. o valor esta associado a classe. nao a um objeto.

    public Empregado(String nome, double salario) { //classe construtora
        this.nome = nome;
        this.salario = salario; // classe com letra maiuscula, metodo com letra minuscula
        // para acessar o nome (que esta privado), devemos criar um metodo get
    }

    public void setTelefone(String telefone) {
        Empregado.telefone = telefone; //variavel de instancia usa this, mas de classe nao.
    }

    @Override // override num metodo que existe acima (herança). se nao tivesse este toString aqui, a gente ia printar o endereço guardado pelo parametro (e1 por exemplo)
    public String toString() {
        return "nome=" + nome + '\'' +
                ", salario=" + salario
                ;
    }

    public static String getTelefone() {
        return telefone;
    }

    public String getNome() {
        return nome;
    }

    public void setSalario(double salario) {
        this.salario = salario; //os sets geralmente sao void, pois nao retornam nada
    }

    public void setNome(String nome) {
        this.nome = nome; //metodos de instancias acima e abaixo
    }

    public double getSalario() {
        return  salario;
    }
}
