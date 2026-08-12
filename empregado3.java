package com.carlosribeiro.projeto03.model;

public class Empregado
{
	private static int contador = 0;
	private int numero;
	private String nome;
	private double salario;
	
	public Empregado (String nome, double salario)
	{
		this.numero = ++contador;
		this.nome = nome;
		this.salario = salario;
	}

	public String toString()
	{	return "Número = " + numero +
			   "  Nome = " + nome +
			   "  Salário = " + salario;
	}

	public int getNumero()
	{	return numero;
	}

	public String getNome()
	{	return nome;
	}
		
	public double getSalario()
	{	return salario;
	}
		
	public void setNome(String nome)
	{	this.nome = nome;
	}
		
	public void setSalario(double salario)
	{	this.salario = salario;
	}
}
