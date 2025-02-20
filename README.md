<p>
  OpenAI Speech-To-Text service for the Freeswitch. <br>
  Available through: asr_interface, cammnad api <br>
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
### Command line
```
freeswitch> openai_asr_transcribe /tmp/test.[wav|mp3] [key=altKey mode=altModel]
+OK: How old is the Brooklyn Bridge
```

### mod_quickjs example
```javascript
session.asrEngine= 'curl';

var txt = session.playAndDetectSpeech('conference/8000/conf-welcome.wav');
consoleLog('info', "TEXT: " + txt);
```
