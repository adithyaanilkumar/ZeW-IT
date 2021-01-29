import 'package:flutter/material.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';
import 'package:zewit/pages/datatable.dart';

class Home extends StatefulWidget {
  @override
  _HomeState createState() => _HomeState();
}

class _HomeState extends State<Home> {
  @override
  
  Widget build(BuildContext context) {
    double width = MediaQuery.of(context).size.width;
    return Scaffold(
      body: Container(
        decoration: BoxDecoration(
          gradient: LinearGradient(
                          colors: [Color.fromRGBO(15,12,41,1),Color.fromRGBO(48,43,99,1),Color.fromRGBO(36, 36,62,1)],
                          begin: Alignment.centerRight,
                          end: Alignment(-1.0, -1.0)
                      ),
        ),
        child: Center(
          child: Container(
            height: MediaQuery.of(context).size.height - 80.0,
              child:Padding(
                  padding: const EdgeInsets.all(8.0),
                  child: Container(
                    width: MediaQuery.of(context).size.width - 35.0,
                    decoration: BoxDecoration(
                      borderRadius: BorderRadius.circular(12.0),
                      color: Color(0xff5a348b),
                      gradient: LinearGradient(
                          colors: [Color.fromRGBO(54,209,220,1),Color.fromRGBO(91,134,229,1)],
                          begin: Alignment.centerRight,
                          end: Alignment(-1.0, -1.0)
                      ), //Gradient
                    ),
                    child: Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: <Widget>[
                            Column(
                              mainAxisAlignment: MainAxisAlignment.center,
                              children: <Widget>[
                                //Text
                                Padding(
                                  padding: const EdgeInsets.only(top: 8.0),
                                  child: Container(
                                    child: Text('Adithya A', style: TextStyle(
                                      color: Colors.white,
                                      fontSize: 30.0,
                                      fontWeight: FontWeight.bold,
                                    ),),
                                  ),
                                ),
                                
                                //Circle Avatar
                                Padding(
                                  padding: const EdgeInsets.only(top: 8.0),
                                  child: Container(
                                 
                                      child: CircleAvatar(
                                        radius:73,
                                        backgroundColor: Colors.black87,
                                        child: CircleAvatar(
                                        backgroundImage: AssetImage("asset/messi.jpg"),
                                         radius: 70,
                                      )
                                      ),
                                     
                                  ),
                                ),

                                //Two Column Table
                                DataTable(
                                  columns: <DataColumn>[
                                    DataColumn(
                                      label: Text(''),
                                    ),
                                    DataColumn(
                                      label: Text(''),
                                    ),
                                  ],
                                  rows: <DataRow>[
                                    DataRow(
                                        cells: <DataCell>[
                                          DataCell(
                                            myRowDataIcon(
                                                FontAwesomeIcons.addressCard, "Card number"),
                                          ),
                                          DataCell(
                                            Text('11275',
                                              style: TextStyle(
                                               fontSize: 15,
                                                color: Colors.white,
                                              ),),
                                          ),
                                        ]
                                    ),
                                    DataRow(
                                        cells: <DataCell>[
                                          DataCell(
                                            myRowDataIcon(
                                                FontAwesomeIcons.gifts,
                                                "Reward Points"),
                                          ),
                                          DataCell(
                                            Text('69', style: TextStyle(
                                              fontSize: 15,
                                              color: Colors.white,
                                            ),),
                                          ),
                                        ]
                                    ),
                                 
                                  ],
                                ),

                                //Button
                                Row(
                                  children: [
                                    Padding(
                                      padding: const EdgeInsets.only(top: 15),
                                      child: RaisedButton(
                                          color: Colors.black,
                                          child: Text('Redeem Points',
                                            style: TextStyle(
                                              color: Colors.white,
                                            ),),
                                          onPressed: () {},
                                          shape: RoundedRectangleBorder(
                                            borderRadius: BorderRadius.circular(
                                                30.0),)
                                      ),
                                    ),
                                    SizedBox(width:5),
                                    Padding(
                                      padding: const EdgeInsets.only(top: 15),
                                      child: RaisedButton(
                                          color: Colors.black,
                                          child: Text('Prototype Bin',
                                            style: TextStyle(
                                              color: Colors.white,
                                            ),),
                                          onPressed: () {
                                             navigateToSubPage(context);
                                                       },
                                          shape: RoundedRectangleBorder(
                                            borderRadius: BorderRadius.circular(
                                                30.0),)
                                      ),
                                    ),
                                  ],
                                ),

                              ],),
                          ],),
                      
                    
                  ),
                ),
                )),
      )

    );
  }
}

Future navigateToSubPage(context) async {
  Navigator.push(context, MaterialPageRoute(builder: (context) => BinData()));
}