import java.util.Scanner;

public class emoticons {
	static Scanner lector = new Scanner (System.in);

	public static void main (String[] args) {
		String envio = "";
		int res;
		int numEmot;
		int numText;

		while (true) {
			res = 0;
			String[] split = lector.nextLine ().trim ().split (" ");
			
			numEmot = Integer.parseInt (split[0]);
			numText = Integer.parseInt (split[1]);
			
			if (numEmot == 0 && numText == 0) {
				System.out.println(envio);
				System.exit (0);
			}
			
			String[] emos = new String[numEmot];
			for (int i = 0; i < emos.length; i++) {
				emos[i] = lector.nextLine ().trim ();
			}
			
			for (int j = 0; j < numText; j++) {
				String line = lector.nextLine ().trim ();

				int[] indexes = new int[emos.length];
				int index;
				boolean exist;
				while (true) {
					index = 0;
					exist = false;
					for (int k = 0; k < emos.length; k++) {
						indexes[k] = line.indexOf (emos[k]);
						if (indexes[k] >= 0) {
							exist |= true;
							if (indexes[index] == -1 || indexes[index] > indexes[k]) {
								index = k;
							}
						}
					}
					if (exist) {
						line = line.substring(indexes[index] + emos[index].length());
						res++;
					} else {
						break;
					}
				}
			}
			
			envio += res + "\n";
		}
	}
}
