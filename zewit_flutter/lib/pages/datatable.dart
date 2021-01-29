import 'package:flutter/material.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';
import 'package:zewit/pages/gmap.dart';
class BinData extends StatefulWidget {
  @override
  _BinDataState createState() => _BinDataState();
}

class _BinDataState extends State<BinData> {
  @override
  Widget build(BuildContext context) {
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
            height: MediaQuery.of(context).size.height*0.85,
              child:Padding(
                  padding: const EdgeInsets.all(4),
                  child: Container(
                    width: MediaQuery
                        .of(context)
                        .size
                        .width - 10.0,
                    decoration: BoxDecoration(
                      borderRadius: BorderRadius.circular(12.0),
                      color: Color(0xff5a348b),
                      gradient: LinearGradient(
                          colors: [Color.fromRGBO(54,209,220,1),Color.fromRGBO(91,134,229,1)],
                          begin: Alignment.centerRight,
                          end: Alignment(-1.0, -1.0)
                      ), //Gradient
                    ),
                    child: Column(
                      children: [
                            Align(
                          alignment: Alignment.topLeft,
                           child: IconButton(
                             color: Colors.white,
                           icon: Icon(Icons.arrow_back),
                           onPressed: () {
                             Navigator.pop(context);
                           },
                           
                          ),
                        ),
                        Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: <Widget>[
                            Column(
                              mainAxisAlignment: MainAxisAlignment.center,
                              children: <Widget>[
                                Padding(
                                  padding: const EdgeInsets.only(top: 8.0),
                                  child: Container(
                                    child: Text('Bin No:1', style: TextStyle(
                                      color: Colors.white,
                                      fontSize: 30.0,
                                      fontWeight: FontWeight.bold,
                                    ),),
                                  ),
                                ),
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
                                          FontAwesomeIcons.trash, "Organic"),
                                          ),
                                          DataCell(
                                            Text('full',
                                              style: TextStyle(
                                                color: Colors.white,
                                                fontSize: 13,
                                              ),),
                                          ),
                                        ]
                                    ),
                                    DataRow(
                                        cells: <DataCell>[
                                          DataCell(
                                            myRowDataIcon(
                                                FontAwesomeIcons.trash,
                                                "Metallic"),
                                          ),
                                          DataCell(
                                            Text('full', style: TextStyle(
                                              color: Colors.white,
                                              fontSize: 13,
                                            ),),
                                          ),
                                        ]
                                    ),
                                     DataRow(
                                        cells: <DataCell>[
                                          DataCell(
                                            myRowDataIcon(
                                                FontAwesomeIcons.trash,
                                                "E-Waste"),
                                          ),
                                          DataCell(
                                            Text('empty', style: TextStyle(
                                              color: Colors.white,
                                              fontSize: 13,
                                            ),),
                                          ),
                                        ]
                                    ),
                                     DataRow(
                                        cells: <DataCell>[
                                          DataCell(
                                            myRowDataIcon(
                                                FontAwesomeIcons.trash,
                                                "Paper"),
                                          ),
                                          DataCell(
                                            Text('empty', style: TextStyle(
                                              color: Colors.white,
                                              fontSize: 13,
                                            ),),
                                          ),
                                        ]
                                    ),
                                     DataRow(
                                        cells: <DataCell>[
                                          DataCell(
                                            myRowDataIcon(
                                                FontAwesomeIcons.trash,
                                                "Plastic"),
                                          ),
                                          DataCell(
                                            Text('full', style: TextStyle(
                                              color: Colors.white,
                                              fontSize: 13,
                                            ),),
                                          ),
                                        ]
                                    ),
                                     DataRow(
                                        cells: <DataCell>[
                                          DataCell(
                                            myRowDataIcon(
                                                FontAwesomeIcons.trash,
                                                "Glass"),
                                          ),
                                          DataCell(
                                            Text('empty', style: TextStyle(
                                              color: Colors.white,
                                              fontSize: 13,
                                            ),),
                                          ),
                                        ]
                                    ),
                                     DataRow(
                                        cells: <DataCell>[
                                          DataCell(
                                            myRowDataIcon(
                                                FontAwesomeIcons.addressCard,
                                                "Driver Number"),
                                          ),
                                          DataCell(
                                            Text('1234567899', style: TextStyle(
                                              color: Colors.white,
                                              fontSize: 13,
                                            ),),
                                          ),
                                        ]
                                    ),
                                     DataRow(
                                        cells: <DataCell>[
                                          DataCell(
                                            myRowDataIcon(
                                                FontAwesomeIcons.gift,
                                                "Reward Status"),
                                          ),
                                          DataCell(
                                            Text('ok', style: TextStyle(
                                              color: Colors.white,
                                              fontSize: 13,
                                            ),),
                                          ),
                                        ]
                                    ),
                                 
                                  ],
                                ),
                                 Padding(
                                      padding: const EdgeInsets.only(top: 8),
                                      child: RaisedButton(
                                          color: new Color(0xffffffff),
                                          child: Text('Navigate To Bin',
                                            style: TextStyle(
                                              color: new Color(0xff6200ee),
                                            ),),
                                          onPressed: () {
                                            navigateToSubPage(context);
                                          },
                                          shape: RoundedRectangleBorder(
                                            borderRadius: BorderRadius.circular(
                                                30.0),)
                                      ),
                                    ),
                                //Button
                                Row(
                                  children: [
                                    Padding(
                                      padding: const EdgeInsets.only(top: 8),
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
                                      padding: const EdgeInsets.only(top: 8),
                                      child: RaisedButton(
                                          color: Colors.black,
                                          child: Text('Prototype Bin',
                                            style: TextStyle(
                                              color: Colors.white,
                                            ),),
                                          onPressed: () {},
                                          shape: RoundedRectangleBorder(
                                            borderRadius: BorderRadius.circular(
                                                30.0),)
                                      ),
                                    ),
                                  ],
                                ),

                              ],),
                          ],),
                      ],
                    ),
                  ),
                ),
                )),
      )
    );
  }
}

ListTile myRowDataIcon(IconData iconVal, String rowVal) {
  return ListTile(
    leading: Icon(iconVal,
        color: new Color(0xffffffff)),
    title: Text(rowVal, style: TextStyle(
      color: Colors.white,
    ),),
  );
}

Future navigateToSubPage(context) async {
  Navigator.push(context, MaterialPageRoute(builder: (context) => Gmap()));
}