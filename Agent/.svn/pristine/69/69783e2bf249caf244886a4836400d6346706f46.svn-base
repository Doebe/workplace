<!DOCTYPE html>
<html lang="en">
	<head>
		<title>HapGL Demo</title>
		<meta charset="utf-8">
		<!-- <meta name="viewport" content="width=device-width, user-scalable=no, minimum-scale=1.0, maximum-scale=1.0"> -->
		<style>
			body {
				font-family: Monospace;
				background-color: #111;
				margin: 0px;
				overflow: hidden;
			}
		</style>
		<link href="styles/clmtrackr/bootstrap.min.css" rel="stylesheet" type="text/css"/>
		<link href="styles/clmtrackr/main.css" rel="stylesheet" type="text/css"/>
        
        <script src="js/common/jquery-1.11.1.min.js"></script>
        
        <script src="js/common/underscore-min.js"></script>
		<script src='js/common/prototype.js'></script>
		<script src="js/common/three.min.js"></script>
        <script src="js/common/stats.min.js"></script>
        <script src='js/common/dat.gui.min.js'></script>
        
		<script src="js/webgl/Detector.js"></script>
		<script src="js/webgl/OrbitControls.js"></script>
		<script src='js/webgl/hap.gui.js'></script>
		<script src='js/webgl/hapgl.js'></script>
        
        <!--JS for clmtrackr-->
		<script src="js/clmtrackr/utils.js"></script>
		<script src="js/clmtrackr/clmtrackr.min.js"></script>
		<script src="js/clmtrackr/models/model_pca_20_svm_emotionDetection.js"></script>
		<!--<script src="js/clmtrackr/Stats.js"></script>-->
		<script src="js/clmtrackr/d3.min.js"></script>
		<script src="js/clmtrackr/emotion_classifier.js"></script>
		<script src="js/clmtrackr/emotionmodel.js"></script>
        
        <!-- JS mainframe -->
        <script src="js/mainframe.classes.js"></script>
	</head>
	
	<body>
        <!--<script src="js/mainframe.js"></script>-->
        
        <script>
            var videoJSEmotion = new FacialExpression();
        </script>
        
        
		<div id="virtual-agent" ></div>
		
		<script src="js/webgl/main.js"></script>
		
		<div id="content">
			<div id="container">
				<video id="videoel" width="300" height="250" preload="auto" loop>
				</video>
				<canvas id="overlay" width="300" height="250"></canvas>
				<div id="emotion_container">
				<div id="emotion_icons">
					<img class="emotion_icon" id="icon1" src="./images/clmtrackr/icon_angry.png">
					<img class="emotion_icon" id="icon2" src="./images/clmtrackr/icon_sad.png">
					<img class="emotion_icon" id="icon3" src="./images/clmtrackr/icon_surprised.png">
					<img class="emotion_icon" id="icon4" src="./images/clmtrackr/icon_happy.png">
				</div>
				<div id='emotion_chart'></div>
			</div>
			</div>
			<canvas id="sketch" width="300" height="250"></canvas>
			
			<script src="js/clmtrackr/main.js"></script>
            
			
			
		</div>
		
		<br>
        
        <!--
        <div id="controls">
            <input class="btn" type="button" value="wait, loading video" disabled="disabled" onclick="startVideo()" id="startbutton"></input>
        </div>
        -->
	</body>
</html>
