const char INDEX_HTML[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>AAAAAA</title>
    <script src="https://code.jquery.com/jquery-3.6.4.min.js" integrity="sha256-oP6HI9z1XaZNBrJURtCoUT5SUnxFr8s3BzRl+cbzUq8=" crossorigin="anonymous"></script>
    <style> 
        /*Estilo Site*/
        /*paleta*/
        :root{
        --azul: #EFA74D;
        --laranja: #3e02ad;
        --branco:#fff;
        --cinzaclaro:#8C8C8C;
        --cinza:#595959;
        --cinzaescuro:#262626;
        --preto:#0D0D0D;
        }
        body{
            text-align: center;
            background-color: var(--laranja);
            font-family: Arial, Helvetica, sans-serif;
            margin: 0;  
        }
        h1{
            font-size: 128px;
            color: var(--azul);
            margin-bottom: 0px;
        }
        h2{
            margin-top: 15px;
            font-size: 36px;
            color: var(--branco);
        }
        fieldset{
            border: 3px solid var(--azul);
            border-radius: 5px;
            margin-left: 40%;
            margin-right: 40%;
            margin-top: 3%;
        }
        #result {
            display: none;
        }

        /*Estilo Botão*/
            .center {
                display: flex;
                flex-direction: column;
                justify-content: center;
                align-items: center;
                margin-top: 3%;
                margin-bottom: 10%;
            }
            .switch {
                position: relative;
                display: inline-block;
                width: 120px;
                height: 68px;
            }
            
            .switch input { 
                opacity: 0;
                width: 0;
                height: 0;
            }
            
            .slider {
                position: absolute;
                cursor: pointer;
                top: 0;
                left: 0;
                right: 0;
                bottom: 0;
                background-color: var(--cinzaescuro);
                -webkit-transition: .4s;
                transition: .4s;
            }
            
            .slider:before {
                position: absolute;
                content: "";
                height: 52px;
                width: 52px;
                left: 8px;
                bottom: 8px;
                background-color: white;
                -webkit-transition: .4s;
                transition: .4s;
            }
            
            input:checked + .slider {
                background-color: var(--azul);
            }
            
            input:focus + .slider {
                box-shadow: 0 0 1px #2196F3;
            }
            
            input:checked + .slider:before {
                -webkit-transform: translateX(52px);
                -ms-transform: translateX(52px);
                transform: translateX(52px);
            }
            
            /* Rounded sliders */
            .slider.round {
                border-radius: 34px;
            }
    
            .slider.round:before {
                border-radius: 50%;
            }
    </style>
</head>
<body>
    <h1>PROTÓTIPO TCC</h1>
    <h2>CONTROLE A MÃO DE ACORDO COM A SUA ESCOLHA</h2>
    <fieldset>
        <div class="center">
            <h2>DEDOS</h2>
            <label class="switch">
                <input type="checkbox" id="checkbox" name="finger">
                <span class="slider round"></span>
              </label>
            <div id="result"></div>
        </div>
        <div class="center">
            <h2>BRAÇO</h2>
            <label class="switch">
                <input type="checkbox" id="checkbox" name="arm">
                <span class="slider round"></span>
              </label>
        </div>
    </fieldset>
    <script>
        let checkboxf = document.querySelector("input[name=finger]");
        let checkboxa = document.querySelector("input[name=arm]");
  
        checkboxf.addEventListener('change', function() {
          if (this.checked) {
            console.log("levantando dedo");
            $("#result").load( "/fingerOn");
          } else {
            console.log("voltando dedo");
            $("#result").load( "/fingerOff");
          }
        });
        checkboxa.addEventListener('change', function() {
          if (this.checked) {
            console.log("girando braço");
            $("#result").load( "/armOn");
          } else {
            console.log("voltando braço");
            $("#result").load( "/armOff");
          }
        });
    </script>
</body>
</html>
)=====";
