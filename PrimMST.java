import java.util.Scanner;

public class PrimMST {
    static int minKey(int[] key, boolean[] inMST, int v) {
        int min = Integer.MAX_VALUE;
        int minIndex = -1;

        for (int i = 0; i < v; i++) {
            if (!inMST[i] && key[i] < min) {
                min = key[i];
                minIndex = i;
            }
        }

        return minIndex;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of vertices: ");
        int v = sc.nextInt();

        int[][] graph = new int[v][v];

        System.out.println("Enter the adjacency matrix (0 if there is no edge):");

        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                graph[i][j] = sc.nextInt();
            }
        }

        int[] key = new int[v];
        int[] parent = new int[v];
        boolean[] inMST = new boolean[v];

        for (int i = 0; i < v; i++) {
            key[i] = Integer.MAX_VALUE;
            inMST[i] = false;
        }

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < v - 1; count++) {
            int u = minKey(key, inMST, v);
            inMST[u] = true;

            for (int w = 0; w < v; w++) {
                if (graph[u][w] != 0 && !inMST[w] && graph[u][w] < key[w]) {
                    parent[w] = u;
                    key[w] = graph[u][w];
                }
            }
        }

        int totalCost = 0;

        System.out.println("Edges in the Minimum Spanning Tree:");

        for (int i = 1; i < v; i++) {
            System.out.println(parent[i] + " - " + i + " : " + graph[i][parent[i]]);
            totalCost += graph[i][parent[i]];
        }

        System.out.println("Total cost of MST = " + totalCost);
        sc.close();
    }
}
