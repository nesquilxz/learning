package com.carlosribeiro.projeto02.model;

public class Empregado {
	private String nome;
	private double salario;
	
	public Empregado (String nome, double salario)
	{	this.nome = nome;
		this.salario = salario;
	}

	//métodos
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

	@Override
	public String toString() {
		return "Nome = " + nome + " salario = " + salario;
	}
}
