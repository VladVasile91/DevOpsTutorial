pipeline {
    agent any

    environment {
        BUILD_SCRIPT = './buildMain.sh'
        TEST_SCRIPT = './runTests.sh'
    }

    stages {

        stage('Build') {
            steps {
                echo "Running build script for branch ${env.BRANCH_NAME}..."
                sh "${BUILD_SCRIPT}"
            }
        }

        stage('Test') {
            steps {
                echo "Running tests..."
                // Run test script, continue even if some tests fail
                sh "${TEST_SCRIPT} || true"

                // Publish Google Test results
                junit 'test/test_results.xml'
            }
        }
    }

    post {
        success {
            echo "✅ Build and tests succeeded for ${env.BRANCH_NAME}"
        }
        failure {
            echo "❌ Build or tests failed for ${env.BRANCH_NAME}"
        }
    }
}
