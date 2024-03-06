
public class Main {

	public static void main(String[] args) {
//		int []a = new int[50];
//		System.out.println(a);

//		Sayi p= new Sayi(100);  //referans
//		Sayi r= new Sayi(200);
//		
//		System.out.println("ilk deger:"+ p.deger);
//		System.out.println(p);
//		System.out.println("ilk deger:"+ r.deger);
//		System.out.println(r);
//		
//		
//		Sayi tmp;
//		tmp = p;
//		p=r;
//		r=tmp;
//		
//		System.out.println("son deger:"+ p.deger);
//		System.out.println("son deger:"+ r.deger);

		Object obj = "Sakarya";
		obj = 125;
		obj = new Sayi(100);
		obj = "Ahmet";
		((Sayi) obj).deger = 250; // unboxing

	}

}
