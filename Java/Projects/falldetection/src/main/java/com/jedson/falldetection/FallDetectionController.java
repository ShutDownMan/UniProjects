package com.jedson.falldetection;

import org.springframework.http.HttpEntity;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class FallDetectionController {

    @PostMapping("/FallDetected")
    public ResponseEntity FallDetected(HttpEntity<String> httpEntit) {
        System.out.println(httpEntit.getBody());

        return ResponseEntity.ok(HttpStatus.OK);
    }

    @PostMapping("/Message")
    public ResponseEntity Message(HttpEntity<String> httpEntit) {
        System.out.println(httpEntit.getBody());

        return ResponseEntity.ok(HttpStatus.OK);
    }

}
