class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        par = {}
        rank = {}

        def find(node):
            curr = par[node]
            while curr != par[curr]:
                curr = par[par[curr]]
                curr = par[curr]
            return curr

        ret = edges[0]
        for edge in edges:
            fst, sec = edge[0], edge[1]
            
            if fst not in par and sec not in par:
                par[fst] = fst
                par[sec] = fst
                rank[sec] = 0
                rank[fst] = 1
            elif fst not in par:
                parent = find(sec)
                par[fst] = parent
                rank[fst] = 0
            elif sec not in par:
                parent = find(fst)
                par[sec] = parent
                rank[sec] = 0
            else:
                par1, par2 = find(fst), find(sec)
                if par1 == par2:
                    ret = edge
                else:
                    if rank[par1] > rank[par2]:
                        par[par2] = par1
                    elif rank[par2] > rank[par1]:
                        par[par1] = par2
                    else:
                        par[par2] = par1
                        rank[par1] += 1
            print(par)
        return ret