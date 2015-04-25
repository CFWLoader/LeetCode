# 项目中潜在的隐患

一个客户端中的IO全都用一个DataOuputStream和DataInputStream，存在并发隐患。<br/>
当然，ChatServer中的ClientService的IO也是一个，目测隐患不小。