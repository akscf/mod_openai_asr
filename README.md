<p>
  OpenAI Speech-To-Text service for the Freeswitch. <br>
  Features: vad, audio keeping, flexible adjustment <br>
  Available through: asr_interface, commnad api <br>
  <br>
  If you have troubles with building this module, pay attention to this <a href="https://github.com/akscf/mod_openai_asr/issues/1">issue</a> and <a href="https://github.com/akscf/mod_openai_asr/issues/1#issuecomment-2339346528"> the comment</a>, 
  maybe you faced the same thing.
</p>

### Dialplan example
```XML
<extension name="openai-asr">
  <condition field="destination_number" expression="^(3222)$">
    <action application="answer"/>
    <action application="play_and_detect_speech" data="/tmp/test2.wav detect:openai"/>
    <action application="sleep" data="1000"/>
    <action application="log" data="CRIT SPEECH_RESULT=${detect_speech_result}"/>
    <action application="hangup"/>
 </condition>
</extension>
```

### mod_quickjs
```javascript
session.ttsEngine= 'openai'; // requires: mod_openai_tts
session.asrEngine= 'openai';

var txt = session.sayAndDetectSpeech('Hello, how can I help you?', 10);
consoleLog('info', "TEXT: " + txt);
```

### Command line
```
freeswitch> openai_asr_transcript /tmp/test.[wav|mp3] [key=altKey mode=altModel]
+OK: How old is the Brooklyn Bridge
```
