import java.util.Arrays;
import java.util.Scanner;

public class KruskalMST {
    static class Edge implements Comparable<Edge> {
        int src, dest, weight;

        Edge(int src, int dest, int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }

        public int compareTo(Edge other) {
            return this.weight - other.weight;
        }
    }

    static int[] parent;

    static int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    static boolean union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB)
            return false;

        parent[rootB] = rootA;
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of vertices: ");
        int v = sc.nextInt();

        System.out.print("Enter number of edges: ");
        int e = sc.nextInt();

        Edge[] edges = new Edge[e];

        System.out.println("Enter source, destination and weight of each edge:");
        for (int i = 0; i < e; i++) {
            int s = sc.nextInt();
            int d = sc.nextInt();
            int w = sc.nextInt();
            edges[i] = new Edge(s, d, w);
        }

        Arrays.sort(edges);

        parent = new int[v];
        for (int i = 0; i < v; i++) {
            parent[i] = i;
        }

        int totalCost = 0;
        int count = 0;

        System.out.println("Edges in the Minimum Spanning Tree:");

        for (Edge edge : edges) {
            if (count == v - 1)
                break;

            if (union(edge.src, edge.dest)) {
                System.out.println(edge.src + " - " + edge.dest + " : " + edge.weight);
                totalCost += edge.weight;
                count++;
            }
        }

        System.out.println("Total cost of MST = " + totalCost);
        sc.close();
    }
}
