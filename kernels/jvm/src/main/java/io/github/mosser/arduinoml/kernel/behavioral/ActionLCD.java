package io.github.mosser.arduinoml.kernel.behavioral;

import io.github.mosser.arduinoml.kernel.generator.Visitable;
import io.github.mosser.arduinoml.kernel.generator.Visitor;
import io.github.mosser.arduinoml.kernel.structural.ActuatorLCD;

public class ActionLCD implements Visitable {

	private boolean displayText;
	private ActuatorLCD actuatorLCD;

	private String text;


	public boolean isDisplayText() {
		return displayText;
	}

	public void setDisplayText(boolean displayText) {
		this.displayText = displayText;
	}

	public ActuatorLCD getActuatorLCD() {
		return actuatorLCD;
	}

	public void setActuatorLCD(ActuatorLCD actuatorLCD) {
		this.actuatorLCD = actuatorLCD;
	}

	public String getText() {
		return text;
	}

	public void setText(String text) {
		this.text = text;
	}

	@Override
	public void accept(Visitor visitor) {
		visitor.visit(this);
	}


	@Override
	public String toString() {
		return "Action{" +
				"displayText=" + displayText +
				", actuator=" + actuatorLCD +
				'}';
	}
}
