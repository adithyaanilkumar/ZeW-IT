var app = {
    // Application Constructor
    initialize: function() {
        this.bindEvents();
    },
    // Bind Event Listeners
    //
    // Bind any events that are required on startup. Common events are:
    // 'load', 'deviceready', 'offline', and 'online'.
    bindEvents: function() {
        document.addEventListener('deviceready', this.onDeviceReady, false);
    },
    // deviceready Event Handler
    //
    // The scope of 'this' is the event. In order to call the 'receivedEvent'
    // function, we must explicitly call 'app.receivedEvent(...);'
    onDeviceReady: function() {
        app.receivedEvent('deviceready');
        jQuery.getJSON("https://api.thingspeak.com/channels/377189/feeds.json?api_key=XCH8DA7AXFPBT2IS&results=1",function(data){
            $('#username').text(data.feeds[0].field1);
            $('#cardno').text(data.feeds[0].field3);
            $('#points').text(data.feeds[0].field5);
        });
    },
    // Update DOM on a Received Event
    receivedEvent: function(id) {
    }
};
var d={};

function display(){
    jQuery.getJSON("https://api.thingspeak.com/channels/360663/feeds.json?results=1",function(data){
        d=data;
        let keys=Object.keys(data.channel);
        for(let i=5;i<keys.length-3;i++){
            $('#info').append('<tr><th>'+data.channel[keys[i]]+'</th><td>'+data.feeds[0][Object.keys(data.feeds[0])[i-3]]+'</td></tr>');
        }
        $('#thead').append("<tr><h6>Details of bin</h6></tr>");
        $('#bin1').remove();
        $("#userdetails").remove();
        $('#buttons').append("<a class='waves-effect waves-light btn blue' onclick='navigate()'>Navigate to bin</a>");//<br/><br/><a class='waves-effect waves-light btn' onclick='call()'>Call Driver</a><a class='waves-effect waves-light btn' onclick='report()'>Report a problem</a>");
    });
}

function navigate(){
     window.open("google.navigation:q="+d.channel.latitude+","+d.channel.longitude+"&mode=d" , '_system');
     //$('#map').css('height','500px');
     //initMap();
}

function call(){
    window.open("tel:"+d.feeds[0].field7,'_system');
}

function report(){
    $('.form').fadeIn(500);
}

function submitform(){
     $('.form').fadeOut(500);
     $('#name').val("");
     $('#complaint').val("");
}

function cancelform(){
     $('.form').fadeOut(500);
     $('#name').val("");
     $('#complaint').val("");
}

//CODE TO EMBED GOOGLE MAPS INSTEAD OF OPENING MAPS APP SEPARATELY
/*
navigator.geolocation.getCurrentPosition(success, error);
var pos={}

function initMap() {
    var directionsService = new google.maps.DirectionsService;
    var directionsDisplay = new google.maps.DirectionsRenderer;
    var map = new google.maps.Map(document.getElementById('map'), {
        zoom: 15,
        center: {lat: 9.9312, lng: 76.2673}
    });
    directionsDisplay.setMap(map);

    function route() {
    directionsService.route({
        origin: {lat: pos.coords.latitude, lng: pos.coords.longitude},
        destination: {lat: parseFloat(d.channel.latitude), lng: parseFloat(d.channel.longitude)},
        travelMode: 'DRIVING'
    }, function(response, status) {
        if (status === 'OK') {
            directionsDisplay.setDirections(response);
        } else {
            window.alert('Directions request failed due to ' + status);
        }
    });
    }
    route();
}

function success(position) {
    pos=position;
}
function error(error) {
    alert(' An Error occured!\nmessage: '+error.message+'\n');
}*/