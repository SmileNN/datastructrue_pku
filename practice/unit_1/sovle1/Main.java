
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		//Scanner cin = new Scanner(new File("./in.txt"));
		Scanner cin = new Scanner(System.in) ;
		int n = cin.nextInt() ;
		for(int i = 0 ; i < n ; i ++){
			TreeMap<Integer, Integer> tree = new TreeMap<Integer, Integer>() ;
			for(int j = 0 ; j < 2 ; ){
				int a = cin.nextInt() ;
				int b = cin.nextInt() ;
				if(b < 0) {
					j ++ ;
					continue ;
				}
				if(tree.get(b) == null){
					tree.put(b, a) ;
				}else{
					tree.put(b, tree.get(b) + a);
				}
			}
			boolean firse = true ;
			
			int ans1[] = new int[tree.size()] ;
			int ans2[] = new int[tree.size()] ;
			int ind = 0 ;
			for(Integer k : tree.keySet()){
				if(tree.get(k) == 0) continue ;
				ans1[ind] = k ;
				ans2[ind] = tree.get(k) ;
				ind ++ ;
			}
			for(int j = ind - 1 ; j >= 0 ; j --){
				if(j != ind - 1) System.out.print(" ");
				System.out.print("[ " + ans2[j] + " " + ans1[j] + " ]");
			}
			System.out.println();
		}
		cin.close();
	}
}

