DIR =0 
FILE = 1 
"""
["FileSystem","mkdir","ls","ls","mkdir","ls","ls","addContentToFile","ls","ls","ls"]
[[],["/goowmfn"],["/goowmfn"],["/"],["/z"],["/"],["/"],["/goowmfn/c","shetopcy"],["/z"],["/goowmfn/c"],["/goowmfn"]]
"""
class FileNode:
    def __init__(self, fileType):
        self.fileType = fileType
        self.content = ''
        self.children = {}
    def ls(self, path:str):
        if path == '/': 
            if self.fileType == DIR:
                return sorted(self.children.keys())
        else:
            us = path[1:].split('/')
            node = self
            for name in us:
                node = node[name]
            return sorted(node.children.keys())
    def mkdir(self, path:str) -> None:
        if path == '/': 
            return 
        us = path[1:].split('/')
        node = self
        for name in us:
            node = node[name]
    def getFile(self, path:str) : 
        if path == '/':
            return None
        us = path[1:].split('/')
        node =self
        for name in us:
            node = node[name] 
        node.fileType = FILE
        node.children[name] = -1
        assert node.fileType == FILE 
        return node 
    def __getitem__(self, index):
        if index in self.children:
            
            return self.children[index]
        self.children[index] = FileNode(DIR)
        return self.children[index]
                
                
            
        
class FileSystem:
  
    def __init__(self):
        self.fs = FileNode(DIR)
        
        

    def ls(self, path: str) -> List[str]:
        return self.fs.ls(path)

    def mkdir(self, path: str) -> None:
        self.fs.mkdir(path)
        

    def addContentToFile(self, filePath: str, content: str) -> None:
        node = self.fs.getFile(filePath)
        node.content += content 
        

    def readContentFromFile(self, filePath: str) -> str:
        node = self.fs.getFile(filePath)
        return node.content 
        


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)
