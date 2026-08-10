package com.pedrohenriques.projeto01;

import com.pedrohenriques.projeto01.model.Empregado;

public class Principal {
    public static void main(String[] args) {
        System.out.println("Olá!");
        Empregado e1 = new Empregado("Tiago", 5000);

        System.out.println(e1.getNome());
        e1.setNome("Thiago");

        Empregado e2 = new Empregado("Lucia", 6000);
        System.out.println("Nome =" + e2.getNome() + " salario = " + e2.getSalario());
        System.out.println(e1); //todas as classes extendem uma classe chamada object, entao a classe empregado... e1 puro retorna tostring (que esta previsto em object)
        System.out.println(Empregado.getTelefone()); //colocamos Empregado porque praticamente todo Empregado tem
        //variavel de instancia variando de objeto varia a variavel, variavel de classe o objeto nao varia
    }


}

